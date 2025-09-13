#pragma once

#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class DarkRoast : public Beverage {
   public:
    DarkRoast() { _description = "Dark Roast Coffee"; }

    double cost() const override { return 0.99; }
};
}  // namespace HeadFirstDesignPatterns::Decorator