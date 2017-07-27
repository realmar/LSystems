#include <memory>

#include "lsystem/base.hpp"
#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::lsystem::concretes;

int main() {
    std::unique_ptr<ILSystem> ils = std::make_unique<KochCurve>();

    ils->GoToIteration(4);
    ils->Print();

    return 0;
}