#pragma once

#include "Beverage.hpp"

namespace HeadFirstDesignPatterns::Decorator {
class CondimentDecorator : public Beverage {
   protected:
    CondimentDecorator() = default;

   public:
    CondimentDecorator(const CondimentDecorator&) = delete;
    void operator=(const CondimentDecorator&) = delete;

    std::string getDescription() const override = 0;
};
}  // namespace HeadFirstDesignPatterns::Decorator