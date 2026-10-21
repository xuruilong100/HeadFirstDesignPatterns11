#pragma once

#include "CaffeineBeverage.hpp"

namespace HeadFirstDesignPatterns::Template::Barista {
class Coffee : public CaffeineBeverage {
   public:
    void brew() const override {
        std::cout << "Dripping Coffee through filter" << std::endl;
    }

    void addCondiments() const override {
        std::cout << "Adding Sugar and Milk" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Template::Barista