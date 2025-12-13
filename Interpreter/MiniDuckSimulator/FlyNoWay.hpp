#pragma once

#include <iostream>
#include "FlyBehavior.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class FlyNoWay : public FlyBehavior {
   public:
    void fly() const override { std::cout << "I can't fly" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator