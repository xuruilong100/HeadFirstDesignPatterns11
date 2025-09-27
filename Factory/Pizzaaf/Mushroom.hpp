#pragma once

#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Mushroom : public Veggies {
   public:
    std::string toString() const override { return "Mushrooms"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract