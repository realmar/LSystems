#include "render/renderer.hpp"
#include "builder/draw.hpp"

#include <iostream>
#include <cmath>
#include <limits>

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

        glfwSetWindowUserPointer(window, custWindow.get());
        glfwSetMouseButtonCallback(window, genericCallback(OnMouseClick));
        glfwSetScrollCallback(window, genericCallback(OnScroll));
        glfwSetKeyCallback(window, genericCallback(OnKey));

        custWindow->OnKey = [this](auto self, int key, int scancode, int action, int mods){
            if(action == GLFW_PRESS) {
                switch (key) {
                    case GLFW_KEY_UP:
                        this->iteration++;
                        break;
                    case GLFW_KEY_DOWN:
                        this->iteration = std::clamp(iteration - 1, 1, std::numeric_limits<int>::max());
                        break;
                    case GLFW_KEY_0:
                        break;
                    case GLFW_KEY_1:
                        break;
                    case GLFW_KEY_2:
                        break;
                    case GLFW_KEY_3:
                        break;
                    case GLFW_KEY_4:
                        break;
                    case GLFW_KEY_5:
                        break;
                    case GLFW_KEY_6:
                        break;
                    case GLFW_KEY_7:
                        break;
                    case GLFW_KEY_8:
                        break;
                    case GLFW_KEY_9:
                        break;
                    default:
                        break;
                }
            }
        };

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        lsystem = facade.GetLSystemNames()->at(1);
    }

    void OpenGLRenderer::Teardown() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void OpenGLRenderer::Render() {
        while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
            // GET INSTRUCTIONS

            DrawInstructions_ptr drawInstructions = facade.GetInstructionsForLSystem(lsystem, (unsigned int)iteration);

            // INIT FRAME

            glClearColor(0.0, 0.0, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            // DRAW FRAME

            if(drawInstructions != nullptr) {
                for(auto i = drawInstructions->begin(); i < drawInstructions->end(); i++) {
                    (*i)->Execute(this);
                }
            }

            // EVENTS AND BUFFERS

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

    void OpenGLRenderer::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    }
}

