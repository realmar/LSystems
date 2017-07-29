#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

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

    void Algae::BuildInstructions(realmar::builder::IDrawBuilder &builder) {

    }
}