#ifndef LSYSTEMS_DRAW_HPP
#define LSYSTEMS_DRAW_HPP

#include <vector>
#include <functional>
#include <memory>

#include "builder/ptrs.hpp"

namespace realmar::builder {
    class IDrawCommand {
    public:
        virtual void Execute() = 0;
    };

    class DrawCommand : public IDrawCommand {
    protected:
        std::function<void ()> memberFunc;
    public:
        DrawCommand(realmar::render::IRenderer *target, RendererMember member);
        DrawCommand(realmar::render::IRenderer *target, RendererMemberArg member, const float& arg);
        void Execute() override;
    };

    class IDrawBuilder {
    public:
        virtual void PutPen() = 0;
        virtual void PullPen() = 0;
        virtual void Move(const float &dist) = 0;
        virtual void Rotate(const float &degrees) = 0;
        virtual void PushPosRot() = 0;
        virtual void PopPosRot() = 0;
        virtual const DrawInstructions& Build() = 0;
    };

    class DrawBuilder : public IDrawBuilder {
    protected:
        realmar::render::IRenderer *target;
        DrawInstructions instructions = std::make_shared<DrawInstructionsValue>();
    public:
        explicit DrawBuilder(realmar::render::IRenderer *target);
        void PutPen() override;
        void PullPen() override;
        void Move(const float &dist) override;
        void Rotate(const float &degrees) override;
        void PushPosRot() override;
        void PopPosRot() override;
        const DrawInstructions& Build() override;
    };
}

#endif //LSYSTEMS_DRAW_HPP
