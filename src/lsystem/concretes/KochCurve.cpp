#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    KochCurve::KochCurve() : BaseLSystem(
            {"F"},
            {"+", "-"},
            "F",
            {
                    ProductionRule("F", "F+F-F-F+F")
            }
    ) { }

    void KochCurve::BuildInstructions(realmar::builder::IDrawBuilder &builder) {

    }
}