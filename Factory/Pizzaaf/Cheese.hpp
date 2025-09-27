#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Cheese {
   public:
    Cheese() = default;
    virtual ~Cheese() = default;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract