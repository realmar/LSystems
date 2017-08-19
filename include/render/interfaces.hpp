#ifndef RENDER_INTERFACES_HPP
#define RENDER_INTERFACES_HPP

#include "builder/ptrs.hpp"

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

        virtual ~IRenderer() = default;
    };
}

#endif //RENDER_INTERFACES_HPP
