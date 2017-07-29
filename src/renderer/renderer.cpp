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

        _window = glfwCreateWindow(512, 512, "L-Systems", nullptr, nullptr);
        if(_window == nullptr){
            std::cerr << "Failed to create window" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(_window);
        glfwSwapInterval(1);

        glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);
    }

    void OpenGLRenderer::Teardown() {
        glfwDestroyWindow(_window);
        glfwTerminate();
    }

    void OpenGLRenderer::Render() {
        while(glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(_window) == 0) {
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

            glfwSwapBuffers(_window);
            glfwPollEvents();
        }
    }

    // drawing
    void OpenGLRenderer::NewDrawing() {
        _posRotStack.clear();
        _currentTransform = {{0, 0}, 0};
    }

    void OpenGLRenderer::PutPen() {
        _penDown = true;
    }

    void OpenGLRenderer::PullPen() {
        _penDown = false;
    }

    void OpenGLRenderer::Move(const float &dist) {
        float y = dist * scale;

        PosRot lastTranform = _currentTransform;
        _currentTransform += PosRot {{0, y}, 0};

        // reset matrix to identity
        glLoadIdentity();
        glRotatef(lastTranform.rot, 0, 1, 0);

        if(_penDown) {
            glBegin(GL_LINE);

            glVertex2f(lastTranform.pos.x, lastTranform.pos.y);
            glVertex2f(_currentTransform.pos.x, _currentTransform.pos.y);

            glEnd();
        }
    }

    void OpenGLRenderer::Rotate(const float &degrees) {
        _currentTransform += PosRot {{0, 0}, degrees};
    }

    void OpenGLRenderer::PushPosRot() {
        _posRotStack.emplace_back(_currentTransform);
    }

    void OpenGLRenderer::PopPosRot() {
        if(_posRotStack.empty())
            return;

        _currentTransform = _posRotStack.back();
        _posRotStack.erase(_posRotStack.end() - 1);

        // reset matrix to identity
        glLoadIdentity();
        glRotatef(_currentTransform.rot, 0, 1, 0);
    }

    std::unique_ptr<IDrawBuilder> OpenGLRenderer::GetDrawBuilder() {
        return std::make_unique<DrawBuilder>(this);
    }
}

