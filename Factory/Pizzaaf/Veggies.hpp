#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Veggies {
   public:
    Veggies() = default;
    virtual ~Veggies() = default;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract