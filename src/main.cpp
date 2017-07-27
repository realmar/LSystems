#include <memory>

#include "base.hpp"
#include "concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::lsystem::concretes;

int main() {
    std::unique_ptr<ILSystem> ils = std::make_unique<BinaryTree>();

    ils->GoToIteration(4);
    ils->Print();

    return 0;
}