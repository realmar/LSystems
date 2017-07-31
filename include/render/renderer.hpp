#ifndef LSYSTEMS_RENDERER_HPP
#define LSYSTEMS_RENDERER_HPP

#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

#include "render/interfaces.hpp"
#include "builder/ptrs.hpp"

namespace realmar::render {
    class OpenGLRenderer : public IRenderer {
    protected:
        GLFWwindow *window = nullptr;

        realmar::builder::DrawInstructions_ptr drawInstructions;
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

        void InjectInstructions(realmar::builder::DrawInstructions_ptr instructions) override;
    };
}

#endif //LSYSTEMS_RENDERER_HPP
