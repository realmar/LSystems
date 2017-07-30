#include <iostream>
#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    DragonCurve::DragonCurve() : BaseLSystem(
            {"X", "Y"},
            {"F", "+", "-"},
            "FX",
            {
                    ProductionRule("X", "X+YF+"),
                    ProductionRule("Y", "-FX-Y")
            }
    ) { }

    void DragonCurve::BuildInstructions(realmar::builder::IDrawBuilder &builder) {
        builder.Move(20);
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