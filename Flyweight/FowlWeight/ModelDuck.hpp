#pragma once

#include <iostream>
#include <string>
#include "Fowl.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class ModelDuck : public Fowl {
   private:
    std::string _type = "Model duck";
    std::string _sound = "<< Silence >>";
    std::string _swim = "sinks";

   public:
    ModelDuck() = default;

    void quack() const override { std::cout << _sound; }

    void swim() const override { std::cout << _swim; }

    std::string toString() const override { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight