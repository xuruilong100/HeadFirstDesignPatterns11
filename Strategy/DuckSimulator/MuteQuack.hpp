#pragma once

#include <iostream>
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Strategy {
class MuteQuack : public QuackBehavior {
   public:
    void quack() const override { std::cout << "<< Silence >>" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Strategy