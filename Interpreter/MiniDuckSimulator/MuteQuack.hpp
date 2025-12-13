#pragma once

#include <iostream>
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class MuteQuack : public QuackBehavior {
   public:
    void quack() const override { std::cout << "<< Silence >>" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator