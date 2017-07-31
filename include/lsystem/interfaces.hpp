#ifndef LSYSTEMS_INTERFACES_HPP
#define LSYSTEMS_INTERFACES_HPP

#include <vector>
#include "builder/interfaces.hpp"

namespace realmar::lsystem::base {
    class ILSystem {
    public:
        virtual std::vector<std::string> GoToIteration(int i) = 0;
        virtual std::string Next() = 0;
        virtual void Print() = 0;
        virtual void Reset() = 0;
        virtual void BuildInstructions(realmar::builder::IDrawBuilder &builder) = 0;
    };
}

namespace realmar::lsystem {
    class ILSystemFactory {
    public:
        virtual std::shared_ptr<base::ILSystem> create() = 0;
    };
}

#endif //LSYSTEMS_INTERFACES_HPP
