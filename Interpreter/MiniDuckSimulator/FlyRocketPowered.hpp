#pragma once

#include <iostream>
#include "FlyBehavior.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class FlyRocketPowered : public FlyBehavior {
   public:
    void fly() const override {
        std::cout << "I'm flying with a rocket" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator