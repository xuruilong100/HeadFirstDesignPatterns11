#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Dough {
   public:
    Dough() = default;
    virtual ~Dough() = default;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract