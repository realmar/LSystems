#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    CantorSet::CantorSet() : BaseLSystem(
            {"A", "B"},
            { },
            "A",
            {
                    ProductionRule("A", "ABA"),
                    ProductionRule("B", "BBB")
            }
    ) { }

    void CantorSet::BuildInstructions(realmar::builder::IDrawBuilder &builder) {

    }
}