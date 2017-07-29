#include "render/renderer.hpp"
#include "builder/draw.hpp"
#include <iostream>

using namespace realmar::builder;

namespace realmar::render {
    Vector2f Vector2f::operator+=(const Vector2f &other) {
        x += other.x;
        y += other.y;

        return Vector2f {x, y};
    }

    PosRot PosRot::operator+=(const PosRot &other) {
        pos += other.pos;
        rot += other.rot;

        return PosRot {pos, rot};
    }

    void OpenGLRenderer::Setup() {
        if(!glfwInit()) {
            std::cerr << "Failed to initialize GLFW"  << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        window = glfwCreateWindow(512, 512, "L-Systems", nullptr, nullptr);
        if(window == nullptr){
            std::cerr << "Failed to create window" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    }

    void OpenGLRenderer::Teardown() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void OpenGLRenderer::Render() {
        while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
            // INIT

            glClearColor(0.0, 0.0, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            // DRAW

            glLoadIdentity();
            glTranslatef(-1, -1, 0);

            glBegin(GL_LINES);
            glVertex2f(0, 0);
            glVertex2f(0.1, 0.1);
            glEnd();

            // EVENTS

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    // drawing
    void OpenGLRenderer::NewDrawing() {
        posRotStack.clear();
        currentTransform = {{0, 0}, 0};
    }

    void OpenGLRenderer::PutPen() {
        penDown = true;
    }

    void OpenGLRenderer::PullPen() {
        penDown = false;
    }

    void OpenGLRenderer::Move(const float &dist) {
        float y = dist * scale;

        PosRot lastTranform = currentTransform;
        currentTransform += PosRot {{0, y}, 0};

        // reset matrix to identity
        glLoadIdentity();
        glRotatef(lastTranform.rot, 0, 1, 0);

        if(penDown) {
            glBegin(GL_LINE);

            glVertex2f(lastTranform.pos.x, lastTranform.pos.y);
            glVertex2f(currentTransform.pos.x, currentTransform.pos.y);

            glEnd();
        }
    }

    void OpenGLRenderer::Rotate(const float &degrees) {
        currentTransform += PosRot {{0, 0}, degrees};
    }

    void OpenGLRenderer::PushPosRot() {
        posRotStack.emplace_back(currentTransform);
    }

    void OpenGLRenderer::PopPosRot() {
        if(posRotStack.empty())
            return;

        currentTransform = posRotStack.back();
        posRotStack.erase(posRotStack.end() - 1);

        // reset matrix to identity
        glLoadIdentity();
        glRotatef(currentTransform.rot, 0, 1, 0);
    }

    std::unique_ptr<IDrawBuilder> OpenGLRenderer::GetDrawBuilder() {
        return std::make_unique<DrawBuilder>(this);
    }

    void OpenGLRenderer::InjectInstructions(realmar::builder::DrawInstructions instructions) {

    }
}

