#pragma once

#include <memory>
#include "CondimentDecorator.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class Mocha : public CondimentDecorator {
   private:
    std::shared_ptr<Beverage> _beverage;

   public:
    explicit Mocha(std::shared_ptr<Beverage> beverage)
        : _beverage(std::move(beverage)) {}

    std::string getDescription() const override {
        return _beverage->getDescription() + ", Mocha";
    }

    double cost() const override { return 0.20 + _beverage->cost(); }
};
}  // namespace HeadFirstDesignPatterns::Decorator