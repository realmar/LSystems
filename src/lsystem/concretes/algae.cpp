#include "algae.hpp"

using namespace realmar::lsystem::base;

namespace realmar::lsystem::concretes {
    Algae::Algae() : BaseLSystem(
        std::vector<std::string> {"A", "B"},
        std::vector<std::string> { },
        "A",
        {
                ProductionRule("A", "AB"),
                ProductionRule("B", "A"),
        }
    ) { };

    std::vector<std::string> Algae::GoToIteration(int i) {
        std::vector<std::string> results;

        for(unsigned int j = 0; j <= i; j++) {
            results.push_back(Next());
        }

        return results;
    }

    std::string Algae::Next() {
        for(std::string::iterator i = result.begin(); i < result.end();) {
            for (const ProductionRule &pr : productionRules) {
                if(std::string(1, *i) == pr.predecessor) {
                    result.replace(i, i + pr.predecessor.length(), pr.successor);
                    i += pr.successor.length();
                    break;
                }
            }
        }

        return result;
    }
}