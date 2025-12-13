#pragma once

#include "Duck.hpp"
#include "FakeQuack.hpp"
#include "FlyNoWay.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class ModelDuck : public Duck {
   public:
    ModelDuck()
        : Duck(std::make_shared<FlyNoWay>(), std::make_shared<FakeQuack>()) {}

    void display() const override {
        std::cout << "I'm a model duck" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator