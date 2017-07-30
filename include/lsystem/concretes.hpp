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
    MAKE_DEFAULT_LSYSTEM(DragonCurve);
    MAKE_DEFAULT_LSYSTEM(FractalPlant);

    class Sierpinski : public realmar::lsystem::base::BaseLSystem {
    protected:
        float angle;
    public:
        explicit Sierpinski(const std::vector<realmar::lsystem::base::ProductionRule> &productionRules =
                {
                        realmar::lsystem::base::ProductionRule("F", "F-G+F+G-F"),
                        realmar::lsystem::base::ProductionRule("G", "GG")
                },
                const float& angle = 120
        );

        void BuildInstructions(realmar::builder::IDrawBuilder& builder) override;
    };

    class SierpinskiArrowhead : public Sierpinski {
    public:
        SierpinskiArrowhead();
    };
}

#endif //LSYSTEMS_CONCRETES_HPP
