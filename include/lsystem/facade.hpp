#ifndef LSYSTEMS_LSYSTEMFACADE_HPP
#define LSYSTEMS_LSYSTEMFACADE_HPP

#include "lsystem/ptrs.hpp"
#include "builder/ptrs.hpp"

namespace realmar::lsystem {
    class LSystemFacade {
    private:
        ILSystem_ptr _lsystem = nullptr;
        std::string _lsystemName = "";
        int _iteration = -1;
        realmar::builder::DrawInstructions_ptr _drawInstructions = nullptr;

        void MakeInstructions();
    public:
        realmar::builder::DrawInstructions_ptr GetInstructionsForLSystem(const std::string &name, const unsigned int &iteration);
        FactoryEnumerate_ptr GetLSystemNames();
    };
}

#endif //LSYSTEMS_LSYSTEMFACADE_HPP
