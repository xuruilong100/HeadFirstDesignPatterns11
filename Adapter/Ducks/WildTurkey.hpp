#pragma once

#include <iostream>
#include "Turkey.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class WildTurkey : public Turkey {
   public:
    void fly() const override {
        std::cout << "I'm flying a short distance" << std::endl;
    }

    void gobble() const override { std::cout << "Gobble gobble" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks