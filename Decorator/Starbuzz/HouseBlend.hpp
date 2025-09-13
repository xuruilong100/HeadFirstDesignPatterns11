#pragma once

#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class HouseBlend : public Beverage {
   public:
    HouseBlend() { _description = "House Blend Coffee"; }

    double cost() const override { return 0.89; }
};
}  // namespace HeadFirstDesignPatterns::Decorator