#pragma once

#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class BlackOlives : public Veggies {
   public:
    std::string toString() const override { return "Black Olives"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract