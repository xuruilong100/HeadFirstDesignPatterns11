#pragma once

#include <iostream>
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Strategy {
class FakeQuack : public QuackBehavior {
   public:
    void quack() const override { std::cout << "Qwak" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Strategy