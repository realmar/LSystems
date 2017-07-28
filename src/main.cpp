#include <memory>

#include "lsystem/base.hpp"
#include "lsystem/concretes.hpp"
#include "render/renderer.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::lsystem::concretes;
using namespace realmar::render;

int main() {
    ILSystem *ils = new BinaryTree();

    ils->GoToIteration(4);
    ils->Print();

    IRenderer *renderer = new OpenGLRenderer();
    renderer->Setup();
    renderer->Render();
    renderer->Teardown();

    delete ils;
    delete renderer;

    return 0;
}