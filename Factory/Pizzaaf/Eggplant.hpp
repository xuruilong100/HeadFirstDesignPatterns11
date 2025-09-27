#pragma once

#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Eggplant : public Veggies {
   public:
    std::string toString() const override { return "Eggplant"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract