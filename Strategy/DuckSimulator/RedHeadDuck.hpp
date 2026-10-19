#pragma once

#include "Duck.hpp"
#include "FlyWithWings.hpp"
#include "Quack.hpp"

namespace HeadFirstDesignPatterns::Strategy {
class RedHead : public Duck {
   public:
    RedHead()
        : Duck(std::make_shared<FlyWithWings>(), std::make_shared<Quack>()) {}

    void display() const override {
        std::cout << "I'm a real Red Headed duck" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Strategy