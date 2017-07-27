#include "render/renderer.hpp"
#include <iostream>

namespace realmar::render {
    void OpenGLRenderer::Setup() {
        if(!glfwInit()) {
            std::cerr << "Failed to initialize GLFW"  << std::endl;
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(1024, 768, "Tutorial 01", nullptr, nullptr);
        if(window == nullptr){
            std::cerr << "Failed to create window" << std::endl;
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);
        glewExperimental=true;

        if (glewInit() != GLEW_OK) {
            std::cerr << "Failed to initialize glew" << std::endl;
        }

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    }

    void OpenGLRenderer::Teardown() {

    }

    void OpenGLRenderer::Run() {
        do{


            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    }
}