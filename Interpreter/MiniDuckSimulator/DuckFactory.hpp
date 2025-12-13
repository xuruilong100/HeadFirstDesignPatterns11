#pragma once

#include <memory>
#include "Duck.hpp"
#include "MallardDuck.hpp"
#include "ModelDuck.hpp"
#include "RedHeadDuck.hpp"
#include "RubberDuck.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class DuckFactory {
   public:
    static std::shared_ptr<Duck> createDuck(int type) {
        if (1 == type)
            return std::make_shared<MallardDuck>();
        else if (2 == type)
            return std::make_shared<RedHeadDuck>();
        else if (3 == type)
            return std::make_shared<RubberDuck>();
        else if (4 == type)
            return std::make_shared<ModelDuck>();
        else
            return nullptr;
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator