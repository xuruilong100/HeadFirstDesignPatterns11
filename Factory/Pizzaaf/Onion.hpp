#pragma once

#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Onion : public Veggies {
   public:
    std::string toString() const override { return "Onion"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract