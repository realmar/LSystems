#include <memory>

#include "base.hpp"
#include "algae.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::lsystem::concretes;

int main() {
    std::unique_ptr<ILSystem> ils = std::make_unique<Algae>();

    ils->GoToIteration(6);
    ils->Print();

    return 0;
}