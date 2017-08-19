#ifndef BUILDER_INTERFACES_HPP
#define BUILDER_INTERFACES_HPP

#include "builder/ptrs.hpp"

namespace realmar::render {
    class IRenderer;
}

namespace realmar::builder {
    class IDrawCommand {
    public:
        virtual void Execute(realmar::render::IRenderer* target) = 0;

        virtual ~IDrawCommand() = default;
    };

    class IDrawBuilder {
    public:
        virtual void PutPen() = 0;
        virtual void PullPen() = 0;
        virtual void Move(const float &dist) = 0;
        virtual void Rotate(const float &degrees) = 0;
        virtual void PushPosRot() = 0;
        virtual void PopPosRot() = 0;
        virtual const DrawInstructions_ptr& Build() = 0;

        virtual ~IDrawBuilder() = default;
    };
}

#endif //BUILDER_INTERFACES_HPP
