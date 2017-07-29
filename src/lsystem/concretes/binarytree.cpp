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
        for(std::string::iterator i = result.begin(); i < result.end(); i++) {
            std::string character(1, *i);

            if(character == "0" || character == "1") {
                builder.PutPen();
                builder.Move(1);
            }else if(character == "[") {
                builder.PullPen();
                builder.PushPosRot();
                builder.Rotate(-45);
            }else if(character == "]") {
                builder.PullPen();
                builder.PopPosRot();
                builder.Rotate(45);
            }else{
                std::cout << "Instruction unknown" << std::endl;
            }
        }
    }
}