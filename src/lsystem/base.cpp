#include <iostream>

#include "lsystem/base.hpp"

using namespace realmar::lsystem::base;
using namespace realmar::builder;

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

    for(unsigned int j = 0; j < i; j++) {
        results.push_back(Next());
    }

    return results;
}

std::string BaseLSystem::Next() {
    for(unsigned int i = 0;;) {
        for (const ProductionRule &pr : productionRules) {
            if(std::string(1, result[i]) == pr.predecessor) {
                result.replace(i, pr.predecessor.length(), pr.successor);
                i += pr.successor.length() - 1;
                break;
            }
        }

        i++;

        if(i >= result.length())
            break;
    }

    return result;
}

void BaseLSystem::Reset() {
    result = axiom;
}

void BaseLSystem::Print() {
    std::cout << result << std::endl;
}

void BaseLSystem::BuildInstructions(realmar::builder::IDrawBuilder &builder) { }