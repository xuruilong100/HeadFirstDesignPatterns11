#pragma once

#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Espresso : public Beverage {
   public:
    Espresso() { _description = "Espresso"; }

    double cost() const override { return 1.99; }
};
}  // namespace HeadFirstDesignPatterns::Decorator