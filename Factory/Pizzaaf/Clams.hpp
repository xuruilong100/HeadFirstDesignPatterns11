#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Clams {
   public:
    Clams() = default;
    virtual ~Clams() = default;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract