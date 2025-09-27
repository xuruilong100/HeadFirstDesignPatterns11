#pragma once

#include "Cheese.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ParmesanCheese : public Cheese {
   public:
    std::string toString() const override { return "Shredded Parmesan"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract