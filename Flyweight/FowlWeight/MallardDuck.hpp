#pragma once

#include <iostream>
#include <string>
#include "Fowl.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class MallardDuck : public Fowl {
   private:
    std::string _type = "Mallard Duck";
    std::string _sound = "Quack";
    std::string _swim = "swims";

   public:
    MallardDuck() = default;

    void quack() const override { std::cout << _sound; }

    void swim() const override { std::cout << _swim; }

    std::string toString() const override { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight