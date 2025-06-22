#pragma once

#include <iostream>
#include "Duck.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class MallardDuck : public Duck {
   public:
    void fly() const override { std::cout << "I'm flying" << std::endl; }
    void quack() const override { std::cout << "Quack" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks