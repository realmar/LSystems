#include "concretes.hpp"

using namespace realmar::lsystem::base;

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
}