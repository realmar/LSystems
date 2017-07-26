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

std::vector<std::string> BaseLSystem::GoToIteration(int i) {
    std::vector<std::string> results;

    for(unsigned int j = 0; j <= i; j++) {
        results.push_back(Next());
    }

    return results;
}

void BaseLSystem::Reset() {
    result = axiom;
}

void BaseLSystem::Print() {
    std::cout << result << std::endl;
}