#pragma once

#include <memory>
#include "CondimentDecorator.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Whip : public CondimentDecorator {
   private:
    std::shared_ptr<Beverage> _beverage;

   public:
    explicit Whip(std::shared_ptr<Beverage> beverage)
        : _beverage(std::move(beverage)) {}

    std::string getDescription() const override {
        return _beverage->getDescription() + ", Whip";
    }

    double cost() const override { return 0.10 + _beverage->cost(); }
};
}  // namespace HeadFirstDesignPatterns::Decorator