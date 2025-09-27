#pragma once

#include "Cheese.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class MozzarellaCheese : public Cheese {
   public:
    std::string toString() const override { return "Shredded Mozzarella"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract