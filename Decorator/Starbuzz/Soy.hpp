#pragma once

#include <memory>
#include "CondimentDecorator.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Soy : public CondimentDecorator {
   private:
    std::shared_ptr<Beverage> _beverage;

   public:
    explicit Soy(std::shared_ptr<Beverage> beverage)
        : _beverage(std::move(beverage)) {}

    std::string getDescription() const override {
        return _beverage->getDescription() + ", Soy";
    }

    double cost() const override { return 0.15 + _beverage->cost(); }
};
}  // namespace HeadFirstDesignPatterns::Decorator