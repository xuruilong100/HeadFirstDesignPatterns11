#pragma once

#include "Duck.hpp"
#include "FlyWithWings.hpp"
#include "Quack.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class MallardDuck : public Duck {
   public:
    MallardDuck()
        : Duck(std::make_shared<FlyWithWings>(), std::make_shared<Quack>()) {}

    void display() const override {
        std::cout << "I'm a real Mallard duck" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator