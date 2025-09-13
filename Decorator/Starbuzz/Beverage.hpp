#pragma once

#include <string>

namespace HeadFirstDesignPatterns::Decorator {
class Beverage {
   protected:
    std::string _description{"Unknown Beverage"};

    Beverage() = default;

   public:
    virtual ~Beverage() = default;

    virtual std::string getDescription() const { return _description; }

    virtual double cost() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Decorator