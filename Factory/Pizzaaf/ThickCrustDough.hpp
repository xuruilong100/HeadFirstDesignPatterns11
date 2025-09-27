#pragma once

#include "Dough.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ThickCrustDough : public Dough {
   public:
    std::string toString() const override { return "Thick Crust Dough"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract