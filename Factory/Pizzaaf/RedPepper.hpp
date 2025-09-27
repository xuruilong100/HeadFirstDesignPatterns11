#pragma once

#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class RedPepper : public Veggies {
   public:
    std::string toString() const override { return "Red Pepper"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract