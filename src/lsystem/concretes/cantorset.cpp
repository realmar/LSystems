#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;

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
}