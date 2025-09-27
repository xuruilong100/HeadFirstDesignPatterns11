#pragma once

#include "Clams.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class FrozenClams : public Clams {
   public:
    std::string toString() const override {
        return "Frozen Clams from Chesapeake Bay";
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract