#pragma once

#include "Duck.hpp"
#include "FlyNoWay.hpp"
#include "Squeak.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class RubberDuck : public Duck {
   public:
    RubberDuck()
        : Duck(std::make_shared<FlyNoWay>(), std::make_shared<Squeak>()) {}

    void display() const override {
        std::cout << "I'm a rubber duck" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator