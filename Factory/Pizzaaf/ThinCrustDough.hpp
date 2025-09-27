#pragma once

#include "Dough.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ThinCrustDough : public Dough {
   public:
    std::string toString() const override { return "Thin Crust Dough"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract