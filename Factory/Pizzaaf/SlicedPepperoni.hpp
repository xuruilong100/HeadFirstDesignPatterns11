#pragma once

#include "Pepperoni.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class SlicedPepperoni : public Pepperoni {
   public:
    std::string toString() const override { return "Sliced Pepperoni"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract