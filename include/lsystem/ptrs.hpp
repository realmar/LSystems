#ifndef LSYSTEMS_PTRS_HPP
#define LSYSTEMS_PTRS_HPP

#include <memory>
#include <map>

#include "lsystem/interfaces.hpp"

namespace realmar::lsystem {
    class ILSystemFactory;

    typedef std::shared_ptr<base::ILSystem> ILSystem_ptr;
    typedef std::shared_ptr<ILSystemFactory> ILSystemFactory_ptr;
    typedef std::map<std::string, ILSystemFactory_ptr> FactoryMap;
}

#endif //LSYSTEMS_PTRS_HPP
