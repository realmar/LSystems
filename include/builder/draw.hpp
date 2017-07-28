#ifndef LSYSTEMS_DRAW_HPP
#define LSYSTEMS_DRAW_HPP

#include "render/renderer.hpp"
#include <vector>
#include <functional>
#include <memory>

namespace realmar::builder {
    typedef void (realmar::render::IRenderer::*RendererMember)();
    typedef void (realmar::render::IRenderer::*RendererMemberArg)(const float&);

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
        virtual const std::vector<std::unique_ptr<IDrawCommand> >& Build() = 0;
    };

    class DrawBuilder : public IDrawBuilder {
    protected:
        realmar::render::IRenderer *target;
        std::vector<std::unique_ptr<IDrawCommand> > instructions;
    public:
        explicit DrawBuilder(realmar::render::IRenderer *target);
        void PutPen() override;
        void PullPen() override;
        void Move(const float &dist) override;
        void Rotate(const float &degrees) override;
        void PushPosRot() override;
        void PopPosRot() override;
        const std::vector<std::unique_ptr<IDrawCommand> >& Build() override;
    };
}

#endif //LSYSTEMS_DRAW_HPP
