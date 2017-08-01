#ifndef LSYSTEMS_RENDERER_HPP
#define LSYSTEMS_RENDERER_HPP

#include<GLFW/glfw3.h>
#include <vector>
#include <memory>
#include <functional>

#include "render/interfaces.hpp"
#include "builder/ptrs.hpp"
#include "lsystem/facade.hpp"

namespace realmar::render {
    #define genericCallback(functionName) \
        [](GLFWwindow* window, auto... args) { \
            auto pointer = static_cast<GLFWCustomWindow*>(glfwGetWindowUserPointer(window)); \
            if (pointer->functionName) pointer->functionName(pointer, args...); \
        }

    class GLFWCustomWindow {
    public:
        std::function<void(GLFWCustomWindow*, int, int, int)> OnMouseClick = [](auto self, int, int, int) {  /* Default is do nothing */ };
        std::function<void(GLFWCustomWindow*, double, double)> OnScroll = [](auto self, double, double) {  /* Default is do nothing */ };
        std::function<void(GLFWCustomWindow*, int, int, int, int)> OnKey = [](auto self, int, int, int, int) {  /* Default is do nothing */ };
    };

    class OpenGLRenderer : public IRenderer {
    protected:
        GLFWwindow *window = nullptr;
        std::shared_ptr<GLFWCustomWindow> custWindow = std::make_shared<GLFWCustomWindow>();
        bool penDown = false;

        realmar::lsystem::LSystemFacade facade;
        int iteration = 1;
    public:
        float scale = 0.016f;

        void Setup() override;
        void Teardown() override;
        void Render() override;

        // drawing
        void NewDrawing() override;
        void PutPen() override;
        void PullPen() override;
        void Move(const float &dist) override;
        void Rotate(const float &degrees) override;
        void PushPosRot() override;
        void PopPosRot() override;

        // callbacks
        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };
}

#endif //LSYSTEMS_RENDERER_HPP
