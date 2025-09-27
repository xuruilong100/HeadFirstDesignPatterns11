#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class NYStyleCheesePizza : public Pizza {
   public:
    NYStyleCheesePizza() {
        _name = "NY Style Sauce and Cheese Pizza";
        _dough = "Thin Crust Dough";
        _sauce = "Marinara Sauce";
        _toppings.emplace_back("Grated Reggiano Cheese");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method