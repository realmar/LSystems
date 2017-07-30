#include <iostream>
#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    FractalPlant::FractalPlant() : BaseLSystem(
            {"X", "F"},
            {"+", "-", "[", "]"},
            "X",
            {
                    ProductionRule("X", "F[-X][X]F[-X]+FX"),
                    ProductionRule("F", "FF")
            }
    ) { }

    void FractalPlant::BuildInstructions(realmar::builder::IDrawBuilder &builder) {


        builder.PutPen();

        FOR_INSTRUCTIONS {
            GET_CHARACTER

            if(character == "F") {
                builder.Move(1);
            }else if(character == "+") {
                builder.Rotate(25);
            }else if(character == "-") {
                builder.Rotate(-25);
            }else if(character == "[") {
                builder.PushPosRot();
            }else if(character == "]") {
                builder.PopPosRot();
            }
        }
    }
}