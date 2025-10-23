#pragma once

#include <iostream>
#include <string>
#include "Fowl.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class RedheadDuck : public Fowl {
   private:
    std::string _type = "Redhead Duck";
    std::string _sound = "Quack";
    std::string _swim = "swims";

   public:
    RedheadDuck() = default;

    void quack() const override { std::cout << _sound; }

    void swim() const override { std::cout << _swim; }

    std::string toString() const override { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight