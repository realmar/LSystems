#ifndef LSYSTEMS_DRAW_HPP
#define LSYSTEMS_DRAW_HPP

#include <vector>
#include <functional>
#include <memory>

#include "builder/ptrs.hpp"
#include "builder/interfaces.hpp"

namespace realmar::builder {
    class DrawCommand : public IDrawCommand {
    protected:
        std::function<void (realmar::render::IRenderer*)> memberFunc;
    public:
        explicit DrawCommand(RendererMember member);
        DrawCommand(RendererMemberArg member, const float& arg);
        void Execute(realmar::render::IRenderer* target) override;
    };

    class DrawBuilder : public IDrawBuilder {
    protected:
        DrawInstructions_ptr instructions = std::make_shared<DrawInstructionsValue>();
    public:
        explicit DrawBuilder();
        void PutPen() override;
        void PullPen() override;
        void Move(const float &dist) override;
        void Rotate(const float &degrees) override;
        void PushPosRot() override;
        void PopPosRot() override;
        const DrawInstructions_ptr& Build() override;
    };
}

#endif //LSYSTEMS_DRAW_HPP
