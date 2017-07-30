#include "lsystem/concretes.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

namespace realmar::lsystem::concretes {
    SierpinskiArrowhead::SierpinskiArrowhead() : Sierpinski(
            {
                    ProductionRule("F", "+G-F-G+"),
                    ProductionRule("G", "-F+G+F-")
            }, 60
    ) { }
}