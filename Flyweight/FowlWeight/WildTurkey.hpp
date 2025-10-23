#pragma once

#include <iostream>
#include <string>
#include "Turkey.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class WildTurkey : public Turkey {
   private:
    std::string _type = "Wild Turkey";
    std::string _sound = "Gobble gobble";
    std::string _walk = "struts";

   public:
    WildTurkey() = default;

    void gobble() const override { std::cout << _sound; }

    void walk() const override { std::cout << _walk; }

    std::string toString() const override { return _type; }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight