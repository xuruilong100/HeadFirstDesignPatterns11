#pragma once

#include "Clams.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class FreshClams : public Clams {
   public:
    std::string toString() const override {
        return "Fresh Clams from Long Island Sound";
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract