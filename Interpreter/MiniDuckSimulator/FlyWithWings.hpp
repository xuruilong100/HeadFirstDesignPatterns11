#pragma once

#include <iostream>
#include "FlyBehavior.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class FlyWithWings : public FlyBehavior {
   public:
    void fly() const { std::cout << "I'm flying!!" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator