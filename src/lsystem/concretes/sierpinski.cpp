#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    Sierpinski::Sierpinski(const std::vector<realmar::lsystem::base::ProductionRule> &productionRules, const float& angle) : BaseLSystem(
            {"F", "G"},
            { "+", "-" },
            "F-G-G",
            productionRules
    ), angle(angle) { }

    void Sierpinski::BuildInstructions(realmar::builder::IDrawBuilder &builder) {
        builder.PutPen();

        FOR_INSTRUCTIONS {
            GET_CHARACTER

            if(character == "F" || character == "G") {
                builder.Move(1);
            }else if(character == "+"){
                builder.Rotate(-angle);
            }else if(character == "-") {
                builder.Rotate(angle);
            }
        };
    }
}