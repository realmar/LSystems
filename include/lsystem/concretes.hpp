#ifndef LSYSTEMS_CONCRETES_HPP
#define LSYSTEMS_CONCRETES_HPP

#include "lsystem/base.hpp"

#define FOR_INSTRUCTIONS for(std::string::iterator i = result.begin(); i < result.end(); i++)
#define GET_CHARACTER std::string character(1, *i);

namespace realmar::lsystem::concretes {
    MAKE_DEFAULT_LSYSTEM(Algae);

    MAKE_DEFAULT_LSYSTEM(BinaryTree);
    MAKE_DEFAULT_LSYSTEM(CantorSet);
    MAKE_DEFAULT_LSYSTEM(KochCurve);
}

#endif //LSYSTEMS_CONCRETES_HPP
