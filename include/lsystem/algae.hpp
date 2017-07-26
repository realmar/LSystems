#ifndef LSYSTEMS_ALGAE_HPP
#define LSYSTEMS_ALGAE_HPP

#include "base.hpp"

namespace realmar::lsystem::concretes {
    class Algae : public realmar::lsystem::base::BaseLSystem {
    public:
        Algae();
        std::string Next() override;
    };
}

#endif //LSYSTEMS_ALGAE_HPP
