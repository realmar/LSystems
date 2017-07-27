#include "render/renderer.hpp"
#include <iostream>

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

    void OpenGLRenderer::Run() {
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
}