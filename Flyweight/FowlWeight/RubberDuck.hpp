#pragma once

#include <iostream>
#include <string>
#include "Fowl.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class RubberDuck : public Fowl {
   private:
    std::string _type = "Rubber Duck";
    std::string _sound = "Squeak";
    std::string _swim = "floats";

   public:
    RubberDuck() = default;

    void quack() const override { std::cout << _sound; }

    void swim() const override { std::cout << _swim; }

    std::string toString() const override { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight