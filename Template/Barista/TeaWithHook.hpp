#pragma once

#include <string>
#include "CaffeineBeverageWithHook.hpp"

namespace HeadFirstDesignPatterns::Template::Barista {
class TeaWithHook : public CaffeineBeverageWithHook {
   public:
    void brew() const override { std::cout << "Steeping the tea" << std::endl; }

    void addCondiments() const override {
        std::cout << "Adding Lemon" << std::endl;
    }

    bool customerWantsCondiments() const override {
        bool value = false;
        if (auto answer = getUserInput(); answer.find('y') != -1) {
            value = true;
        }
        return value;
    }

   private:
    std::string getUserInput() const {
        std::string value;
        std::cout << "Would you like lemon with your tea (y/n)? " << std::endl;
        std::cin >> value;
        return value;
    }
};
}  // namespace HeadFirstDesignPatterns::Template::Barista