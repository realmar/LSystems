#include <iostream>
#include "lsystem/base.hpp"
#include "lsystem/concretes.hpp"
#include "render/renderer.hpp"
#include "lsystem/facade.hpp"

using namespace realmar::lsystem;
using namespace realmar::lsystem::base;
using namespace realmar::lsystem::concretes;
using namespace realmar::render;
using namespace realmar::builder;

int main() {
    IRenderer *renderer = new OpenGLRenderer();

    renderer->Setup();
    renderer->Render();
    renderer->Teardown();

    delete renderer;

    return 0;
}