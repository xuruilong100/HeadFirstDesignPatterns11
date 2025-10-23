#pragma once

#include <string>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class Turkey {
   public:
    virtual ~Turkey() = default;

    virtual void gobble() const = 0;

    virtual void walk() const = 0;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight