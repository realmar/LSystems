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
        builder.PutPen();
        builder.Rotate(90);

        FOR_INSTRUCTIONS {
            GET_CHARACTER

            if(character == "F") {
                builder.Move(1);
            }else if(character == "+") {
                builder.Rotate(-90);
            }else if(character == "-") {
                builder.Rotate(90);
            }
        };
    }
}