#ifndef BUILDER_PTRS_HPP
#define BUILDER_PTRS_HPP

#include <vector>
#include <memory>

namespace realmar::render {
    class IRenderer;
}

namespace realmar::builder {
    class IDrawCommand;

    typedef void (realmar::render::IRenderer::*RendererMember)();
    typedef void (realmar::render::IRenderer::*RendererMemberArg)(const float&);

    typedef std::unique_ptr<IDrawCommand> DrawInstruction_ptr;
    typedef std::vector<DrawInstruction_ptr> DrawInstructionsValue;
    typedef std::shared_ptr<DrawInstructionsValue> DrawInstructions_ptr;
}

#endif //LSYSTEMS_PTRS_HPP
