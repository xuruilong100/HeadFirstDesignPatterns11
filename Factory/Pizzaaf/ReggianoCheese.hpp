#pragma once

#include "Cheese.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ReggianoCheese : public Cheese {
   public:
    std::string toString() const override { return "Reggiano Cheese"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract