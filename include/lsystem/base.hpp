#ifndef LSYSTEMS_BASE_HPP
#define LSYSTEMS_BASE_HPP

#include <string>
#include <vector>

#define MAKE_DEFAULT_LSYSTEM(name) \
class name : public realmar::lsystem::base::BaseLSystem { \
public: \
    name(); \
};

namespace realmar::lsystem::base {
    class ProductionRule {
    public:
        const std::string predecessor;
        const std::string successor;

        ProductionRule(const std::string &predecessor, const std::string &successor);
    };

    class ILSystem {
    public:
        virtual std::vector<std::string> GoToIteration(int i) = 0;
        virtual std::string Next() = 0;
        virtual void Print() = 0;
        virtual void Reset() = 0;
    };

    class BaseLSystem : public ILSystem {
    public:

        std::vector<std::string> alphabet;
        std::vector<std::string> constants;
        std::string axiom;
        std::vector<ProductionRule> productionRules;

        std::string result;

        BaseLSystem(const std::vector<std::string> &alphabet,
                    const std::vector<std::string> &constants,
                    const std::string &axiom,
                    const std::vector<ProductionRule> &productionRules);

        virtual ~BaseLSystem() = default;
        std::vector<std::string> GoToIteration(int i) override;
        std::string Next() override;
        void Reset() override;
        void Print() override;
    };
}

#endif //LSYSTEMS_BASE_HPP
