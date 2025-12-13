#pragma once

#include <iostream>
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class FakeQuack : public QuackBehavior {
   public:
    void quack() const override { std::cout << "Qwak" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator