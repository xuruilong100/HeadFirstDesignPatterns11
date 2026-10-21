#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Template::Barista {
class CaffeineBeverage {
   public:
    CaffeineBeverage() = default;
    virtual ~CaffeineBeverage() = default;

    virtual void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

   protected:
    virtual void brew() const = 0;

    virtual void addCondiments() const = 0;

    void boilWater() const { std::cout << "Boiling water" << std::endl; }

    void pourInCup() const { std::cout << "Pouring into cup" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Template::Barista