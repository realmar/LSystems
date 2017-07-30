#include "render/renderer.hpp"
#include "builder/draw.hpp"
#include <iostream>
#include <cmath>

using namespace realmar::builder;

namespace realmar::render {
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

            if(drawInstructions != nullptr) {
                for(auto i = drawInstructions->begin(); i < drawInstructions->end(); i++) {
                    (*i)->Execute();
                }
            }

            // EVENTS

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    // drawing
    void OpenGLRenderer::NewDrawing() {
        PullPen();
        glLoadIdentity();
        glTranslatef(0, -1, 0);
    }

    void OpenGLRenderer::PutPen() {
        penDown = true;
    }

    void OpenGLRenderer::PullPen() {
        penDown = false;
    }

    void OpenGLRenderer::Move(const float &dist) {
        float y = dist * scale;

        if(penDown) {
            glBegin(GL_LINES);

            glVertex2f(0, 0);
            glVertex2f(0, y);

            glEnd();
        }

        glTranslatef(0, y, 0);
    }

    void OpenGLRenderer::Rotate(const float &degrees) {
        glRotatef(-degrees, 0, 0, 1);
    }

    void OpenGLRenderer::PushPosRot() {
        glPushMatrix();
    }

    void OpenGLRenderer::PopPosRot() {
        glPopMatrix();
    }

    std::unique_ptr<IDrawBuilder> OpenGLRenderer::GetDrawBuilder() {
        return std::make_unique<DrawBuilder>(this);
    }

    void OpenGLRenderer::InjectInstructions(realmar::builder::DrawInstructions instructions) {
        drawInstructions = instructions;
    }
}

