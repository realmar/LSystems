#ifndef LSYSTEMS_RENDERER_HPP
#define LSYSTEMS_RENDERER_HPP

#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

#include "builder/draw.hpp"

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

        virtual std::unique_ptr<realmar::builder::IDrawBuilder> GetDrawBuilder() = 0;
        virtual void InjectInstructions(realmar::builder::DrawInstructions instructions) = 0;
    };

    class OpenGLRenderer : public IRenderer {
    protected:
        GLFWwindow *window = nullptr;

        realmar::builder::DrawInstructions drawInstructions;
        bool penDown = false;
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

        std::unique_ptr<realmar::builder::IDrawBuilder> GetDrawBuilder() override;
        void InjectInstructions(realmar::builder::DrawInstructions instructions) override;
    };
}

#endif //LSYSTEMS_RENDERER_HPP
