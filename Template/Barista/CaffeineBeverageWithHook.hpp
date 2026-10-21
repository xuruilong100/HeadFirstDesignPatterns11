#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Template::Barista {
class CaffeineBeverageWithHook {
   public:
    CaffeineBeverageWithHook() = default;
    virtual ~CaffeineBeverageWithHook() = default;

    virtual void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }

    virtual void brew() const = 0;

    virtual void addCondiments() const = 0;

   protected:
    virtual void boilWater() const {
        std::cout << "Boiling water" << std::endl;
    }

    virtual void pourInCup() const {
        std::cout << "Pouring into cup" << std::endl;
    }

    virtual bool customerWantsCondiments() const { return true; }
};
}  // namespace HeadFirstDesignPatterns::Template::Barista