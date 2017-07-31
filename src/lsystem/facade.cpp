#include "lsystem/facade.hpp"
#include "lsystem/factory.hpp"
#include "builder/draw.hpp"

using namespace realmar::builder;

namespace realmar::lsystem {
    realmar::builder::DrawInstructions_ptr LSystemFacade::GetInstructionsForLSystem(const std::string &name,
                                                                                    const unsigned int &iteration) {
        if(_lsystemName != name) {
            try {
                _lsystem = LSystemFactory::Create(name);
            }catch (const FactoryNotFound& e) {
                // handle
            }

            _lsystem->GoToIteration(iteration);
            MakeInstructions();
        }else if(_lsystem != nullptr) {
            if(_iteration < iteration) {
                for(unsigned int i = 0; i <= iteration - _iteration; i++)
                    _lsystem->Next();
                MakeInstructions();
            }else if(_iteration > iteration) {
                _lsystem->GoToIteration(iteration);
            }
        }

        _iteration = iteration;
        _lsystemName = name;

        return _drawInstructions;
    }

    void LSystemFacade::MakeInstructions() {
        DrawBuilder builder;
        _lsystem->BuildInstructions(builder);
        _drawInstructions = builder.Build();
    }
}