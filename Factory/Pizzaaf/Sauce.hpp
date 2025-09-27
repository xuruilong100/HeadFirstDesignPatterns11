#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Sauce {
   public:
    Sauce() = default;
    virtual ~Sauce() = default;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract