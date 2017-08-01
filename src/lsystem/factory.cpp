#include <iostream>
#include "lsystem/factory.hpp"

using namespace realmar::lsystem;

const char *FactoryNotFound::what() const throw() {
    return "Requested factory was not found.";
}

void LSystemFactory::RegisterType(std::pair<std::string, ILSystemFactory_ptr> factory) {
    GetFactoryMap().emplace(factory);
}

ILSystem_ptr LSystemFactory::Create(const std::string &name) {
    auto factory = GetFactoryMap().find(name);
    if(factory != GetFactoryMap().end()) {
        return factory->second->create();
    }

    throw FactoryNotFound();
}

FactoryEnumerate_ptr LSystemFactory::EnumerateFactories() {
    FactoryEnumerate_ptr enumerate = std::make_shared<FactoryEnumerateValue>();

    for (auto &i : GetFactoryMap()) {
        enumerate->emplace_back(i.first);
    }

    return enumerate;
}