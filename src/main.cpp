#include <iostream>
#include "lsystem/base.hpp"
#include "lsystem/concretes.hpp"
#include "render/renderer.hpp"
#include "builder/draw.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::lsystem::concretes;
using namespace realmar::render;
using namespace realmar::builder;

int main() {
    ILSystem *ils = new BinaryTree();

    ils->GoToIteration(6);
    ils->Print();

    IRenderer *renderer = new OpenGLRenderer();

    DrawBuilder builder(renderer);
    ils->BuildInstructions(builder);
    DrawInstructions instructions = builder.Build();

    renderer->Setup();
    renderer->InjectInstructions(instructions);
    renderer->Render();
    renderer->Teardown();

    delete ils;
    delete renderer;

    return 0;
}