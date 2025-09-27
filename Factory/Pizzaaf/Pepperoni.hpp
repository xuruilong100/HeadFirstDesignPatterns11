#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Pepperoni {
   public:
    Pepperoni() = default;
    virtual ~Pepperoni() = default;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract