#include "concretes.hpp"

using namespace realmar::lsystem::base;

namespace realmar::lsystem::concretes {
    Algae::Algae() : BaseLSystem(
        {"A", "B"},
        { },
        "A",
        {
                ProductionRule("A", "AB"),
                ProductionRule("B", "A"),
        }
    ) { };
}