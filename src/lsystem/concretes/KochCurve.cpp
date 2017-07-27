#include "concretes.hpp"

using namespace realmar::lsystem::base;

namespace realmar::lsystem::concretes {
    KochCurve::KochCurve() : BaseLSystem(
            {"F"},
            {"+", "-"},
            "F",
            {
                    ProductionRule("F", "F+F-F-F+F")
            }
    ) { }
}