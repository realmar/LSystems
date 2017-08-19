#ifndef LSYSTEMS_FACTORY_HPP
#define LSYSTEMS_FACTORY_HPP

#include <map>
#include <string>
#include <memory>
#include <exception>

#include "lsystem/interfaces.hpp"
#include "lsystem/ptrs.hpp"

#define MAKE_DEFAULT_FACTORY(name) \
class name##Factory : public ILSystemFactory { \
public: \
    name##Factory() { \
        realmar::lsystem::LSystemFactory::RegisterType( \
            std::make_pair(#name, std::make_shared<name##Factory>(*this)) ); \
    } \
    ILSystem_ptr create() override { \
        return std::make_shared<realmar::lsystem::concretes::name>(); \
    } \
}; \
static name##Factory global_##name##Factory;

namespace realmar::lsystem::base {
    class ILSystem;
}

namespace realmar::lsystem {
    class FactoryNotFound : public std::exception {
        const char *what() const throw();
    };

    class LSystemFactory {
    private:
        // https://stackoverflow.com/questions/8057682/accessing-a-static-map-from-a-static-member-function-segmentation-fault-c?rq=1
        static FactoryMap &GetFactoryMap() {
            static FactoryMap fmap;
            return fmap;
        }
    public:
        static void RegisterType(std::pair<std::string, ILSystemFactory_ptr> factory);
        static ILSystem_ptr Create(const std::string &name);
        static FactoryEnumerate_ptr EnumerateFactories();

        virtual ~LSystemFactory() = default;
    };
}

#endif //LSYSTEMS_FACTORY_HPP
