#pragma once

#include "Sauce.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class MarinaraSauce : public Sauce {
   public:
    std::string toString() const override { return "Marinara Sauce"; }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract