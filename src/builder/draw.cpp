#include "builder/draw.hpp"
#include "render/renderer.hpp"

using namespace realmar::render;
using namespace realmar::builder;

DrawBuilder::DrawBuilder(IRenderer *target) : target(target) {
    instructions->emplace_back(std::make_unique<DrawCommand>(target, &IRenderer::NewDrawing));
}

void DrawBuilder::PutPen() {
    instructions->emplace_back(std::make_unique<DrawCommand>(target, &IRenderer::PutPen));
}

void DrawBuilder::PullPen() {
    instructions->emplace_back(std::make_unique<DrawCommand>(target, &IRenderer::PullPen));
}

void DrawBuilder::Move(const float &dist) {
    instructions->emplace_back(std::make_unique<DrawCommand>(target, &IRenderer::Move, dist));
}

void DrawBuilder::Rotate(const float &degrees) {
    instructions->emplace_back(std::make_unique<DrawCommand>(target, &IRenderer::Rotate, degrees));
}

void DrawBuilder::PushPosRot() {
    instructions->emplace_back(std::make_unique<DrawCommand>(target, &IRenderer::PushPosRot));
}

void DrawBuilder::PopPosRot() {
    instructions->emplace_back(std::make_unique<DrawCommand>(target, &IRenderer::PullPen));
}

const DrawInstructions& DrawBuilder::Build() {
    return instructions;
}

DrawCommand::DrawCommand(IRenderer *target, RendererMember member) {
    auto m = std::bind(member, target);
    memberFunc = [&m](){ m(); };
}

DrawCommand::DrawCommand(IRenderer *target, RendererMemberArg member, const float& arg) {
    auto m = std::bind(member, target, arg);
    memberFunc = [&m](){ m(); };
}

void DrawCommand::Execute() {
    memberFunc();
}