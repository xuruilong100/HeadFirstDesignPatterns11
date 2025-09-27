#pragma once

#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Garlic : public Veggies {
   public:
    std::string toString() const override { return "Garlic"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract