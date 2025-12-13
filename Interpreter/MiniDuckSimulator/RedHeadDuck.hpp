#pragma once

#include "Duck.hpp"
#include "FlyWithWings.hpp"
#include "Quack.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class RedHeadDuck : public Duck {
   public:
    RedHeadDuck()
        : Duck(std::make_shared<FlyWithWings>(), std::make_shared<Quack>()) {}

    void display() const override {
        std::cout << "I'm a real Red Headed duck" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator