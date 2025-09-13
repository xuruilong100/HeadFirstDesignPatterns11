#pragma once

#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Decaf : public Beverage {
   public:
    Decaf() { _description = "Decaf Coffee"; }

    double cost() const override { return 1.05; }
};
}  // namespace HeadFirstDesignPatterns::Decorator