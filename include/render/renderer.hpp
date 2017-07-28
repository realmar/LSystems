#ifndef LSYSTEMS_RENDERER_HPP
#define LSYSTEMS_RENDERER_HPP

#include <GLFW/glfw3.h>

namespace realmar::render {
    class IRenderer {
    public:
        virtual void Setup() = 0;
        virtual void Teardown() = 0;
        virtual void Render() = 0;

        // drawing
        virtual void NewDrawing() = 0;
        virtual void PutPen() = 0;
        virtual void PullPen() = 0;
        virtual void Move(const float &dist) = 0;
        virtual void Rotate(const float &degrees) = 0;
        virtual void PushPosRot() = 0;
        virtual void PopPosRot() = 0;
    };

    class OpenGLRenderer : public IRenderer {
    private:
        GLFWwindow *window = nullptr;
    public:
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
    };
}

#endif //LSYSTEMS_RENDERER_HPP
