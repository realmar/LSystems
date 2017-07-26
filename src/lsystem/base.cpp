#include <iostream>

#include "base.hpp"

using namespace realmar::lsystem::base;

ProductionRule::ProductionRule(const std::string &predecessor, const std::string &successor) : predecessor(predecessor),
                                                                                               successor(successor) { }

BaseLSystem::BaseLSystem(const std::vector<std::string> &alphabet,
                         const std::vector<std::string> &constants,
                         const std::string &axiom,
                         const std::vector<ProductionRule> &productionRules) : alphabet(alphabet),
                                                                               constants(constants),
                                                                               axiom(axiom),
                                                                               productionRules(productionRules){
    Reset();
}

void BaseLSystem::Reset() {
    result = axiom;
}

void BaseLSystem::Print() {
    std::cout << result << std::endl;
}