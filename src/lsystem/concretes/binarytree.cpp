#include <iostream>
#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    BinaryTree::BinaryTree() : BaseLSystem(
            {"0", "1"},
            {"[", "]"},
            "0",
            {
                    ProductionRule("1", "11"),
                    ProductionRule("0", "1[0]0")
            }
    ) { }

    void BinaryTree::BuildInstructions(realmar::builder::IDrawBuilder &builder) {
        builder.PutPen();

        FOR_INSTRUCTIONS {
            GET_CHARACTER

            if(character == "0" || character == "1") {
                builder.Move(1);
            }else if(character == "[") {
                builder.PushPosRot();
                builder.Rotate(-45);
            }else if(character == "]") {
                builder.PopPosRot();
                builder.Rotate(45);
            }else{
                std::cout << "Instruction unknown" << std::endl;
            }
        }
    }
}