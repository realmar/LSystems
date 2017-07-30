#include <iostream>
#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    LevyCCurve::LevyCCurve() : BaseLSystem(
            {"F"},
            {"+", "-"},
            "F",
            {
                    ProductionRule("F", "+F--F+"),
            }
    ) { }

    void LevyCCurve::BuildInstructions(realmar::builder::IDrawBuilder &builder) {
        builder.Move(40);
        builder.Rotate(-90);
        builder.Move(-30);
        builder.PutPen();

        FOR_INSTRUCTIONS {
            GET_CHARACTER

            if(character == "F") {
                builder.Move(1);
            }else if(character == "+") {
                builder.Rotate(45);
            }else if(character == "-") {
                builder.Rotate(-45);
            }
        }
    }
}