#pragma once

#include <iostream>
#include "FlyBehavior.hpp"

namespace HeadFirstDesignPatterns::Strategy {
class FlyWithWings : public FlyBehavior {
   public:
    void fly() const override { std::cout << "I'm flying!!" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Strategy