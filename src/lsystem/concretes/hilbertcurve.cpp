#include <iostream>
#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    HilbertCurve::HilbertCurve() : BaseLSystem(
            {"A", "B"},
            {"F", "+", "-"},
            "A",
            {
                    ProductionRule("A", "-BF+AFA+FB-"),
                    ProductionRule("B", "+AF-BFB-FA+")
            }
    ) { }

    void HilbertCurve::BuildInstructions(realmar::builder::IDrawBuilder &builder) {
        builder.PutPen();

        FOR_INSTRUCTIONS {
            GET_CHARACTER

            if(character == "F") {
                builder.Move(1);
            }else if(character == "+") {
                builder.Rotate(90);
            }else if(character == "-") {
                builder.Rotate(-90);
            }
        }
    }
}