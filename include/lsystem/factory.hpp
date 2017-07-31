#ifndef LSYSTEMS_FACTORY_HPP
#define LSYSTEMS_FACTORY_HPP

#include <map>
#include <string>
#include <memory>
#include <exception>

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

    typedef std::shared_ptr<base::ILSystem> ILSystem_ptr;

    class ILSystemFactory {
    public:
        virtual ILSystem_ptr create() = 0;
    };

    typedef std::shared_ptr<ILSystemFactory> ILSystemFactory_ptr;
    typedef std::map<std::string, ILSystemFactory_ptr> FactoryMap;

    class LSystemFactory {
    private:
        static FactoryMap &GetFactoryMap() {
            static FactoryMap fmap;
            return fmap;
        }
    public:
        static void RegisterType(std::pair<std::string, ILSystemFactory_ptr> factory);
        static ILSystem_ptr Create(const std::string &name);
    };
}

#endif //LSYSTEMS_FACTORY_HPP
