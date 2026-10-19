#pragma once

#include <iostream>
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Strategy {
class Quack : public QuackBehavior {
   public:
    void quack() const override { std::cout << "Quack" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Strategy