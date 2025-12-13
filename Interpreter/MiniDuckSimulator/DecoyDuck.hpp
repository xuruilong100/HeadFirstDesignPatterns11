#pragma once

#include "Duck.hpp"
#include "FlyNoWay.hpp"
#include "MuteQuack.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class DecoyDuck : public Duck {
   public:
    DecoyDuck()
        : Duck(std::make_shared<FlyNoWay>(), std::make_shared<MuteQuack>()) {}

    void display() const override {
        std::cout << "I'm a duck Decoy" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator