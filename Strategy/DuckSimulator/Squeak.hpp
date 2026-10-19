#pragma once

#include <iostream>
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Strategy {
class Squeak : public QuackBehavior {
   public:
    void quack() const override { std::cout << "Squeak" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Strategy