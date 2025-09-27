#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class NYStylePepperoniPizza : public Pizza {
   public:
    NYStylePepperoniPizza() {
        _name = "NY Style Pepperoni Pizza";
        _dough = "Thin Crust Dough";
        _sauce = "Marinara Sauce";
        _toppings.emplace_back("Grated Reggiano Cheese");
        _toppings.emplace_back("Sliced Pepperoni");
        _toppings.emplace_back("Garlic");
        _toppings.emplace_back("Onion");
        _toppings.emplace_back("Mushrooms");
        _toppings.emplace_back("Red Pepper");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method