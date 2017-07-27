#ifndef LSYSTEMS_RENDERER_HPP
#define LSYSTEMS_RENDERER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace realmar::render {
    class IRenderer {
    public:
        virtual void Setup() = 0;
        virtual void Teardown() = 0;
        virtual void Run() = 0;
    };

    class OpenGLRenderer : public IRenderer {
    private:
        GLFWwindow *window = nullptr;
    public:
        void Setup() override;
        void Teardown() override;
        void Run() override;
    };
}

#endif //LSYSTEMS_RENDERER_HPP
