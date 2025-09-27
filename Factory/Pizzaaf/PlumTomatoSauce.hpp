#pragma once

#include "Sauce.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class PlumTomatoSauce : public Sauce {
   public:
    std::string toString() const override {
        return "Tomato sauce with plum tomatoes";
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract