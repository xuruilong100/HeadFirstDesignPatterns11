#pragma once

#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Spinach : public Veggies {
   public:
    std::string toString() const override { return "Spinach"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract