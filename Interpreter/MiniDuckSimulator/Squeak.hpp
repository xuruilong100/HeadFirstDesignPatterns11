#pragma once

#include <iostream>
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class Squeak : public QuackBehavior {
   public:
    void quack() const override { std::cout << "Squeak" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator