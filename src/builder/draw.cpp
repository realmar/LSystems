#include <iostream>
#include "builder/draw.hpp"
#include "render/renderer.hpp"

using namespace realmar::render;
using namespace realmar::builder;

DrawBuilder::DrawBuilder() {
    instructions->emplace_back(std::make_unique<DrawCommand>(&IRenderer::NewDrawing));
}

void DrawBuilder::PutPen() {
    instructions->emplace_back(std::make_unique<DrawCommand>(&IRenderer::PutPen));
}

void DrawBuilder::PullPen() {
    instructions->emplace_back(std::make_unique<DrawCommand>(&IRenderer::PullPen));
}

void DrawBuilder::Move(const float &dist) {
    instructions->emplace_back(std::make_unique<DrawCommand>(&IRenderer::Move, dist));
}

void DrawBuilder::Rotate(const float &degrees) {
    instructions->emplace_back(std::make_unique<DrawCommand>(&IRenderer::Rotate, degrees));
}

void DrawBuilder::PushPosRot() {
    instructions->emplace_back(std::make_unique<DrawCommand>(&IRenderer::PushPosRot));
}

void DrawBuilder::PopPosRot() {
    instructions->emplace_back(std::make_unique<DrawCommand>(&IRenderer::PopPosRot));
}

const DrawInstructions_ptr& DrawBuilder::Build() {
    return instructions;
}

DrawCommand::DrawCommand(RendererMember member) {
    memberFunc = std::bind(member, std::placeholders::_1);
}

DrawCommand::DrawCommand(RendererMemberArg member, const float& arg) {
    memberFunc = std::bind(member, std::placeholders::_1, arg);
}

void DrawCommand::Execute(realmar::render::IRenderer *target) {
    memberFunc(target);
}