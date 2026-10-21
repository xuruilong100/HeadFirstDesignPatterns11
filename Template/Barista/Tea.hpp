#pragma once

#include "CaffeineBeverage.hpp"

namespace HeadFirstDesignPatterns::Template::Barista {
class Tea : public CaffeineBeverage {
   public:
    void brew() const override { std::cout << "Steeping the tea" << std::endl; }

    void addCondiments() const override {
        std::cout << "Adding Lemon" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Template::Barista