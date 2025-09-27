#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class NYStyleVeggiePizza : public Pizza {
   public:
    NYStyleVeggiePizza() {
        _name = "NY Style Veggie Pizza";
        _dough = "Thin Crust Dough";
        _sauce = "Marinara Sauce";
        _toppings.emplace_back("Grated Reggiano Cheese");
        _toppings.emplace_back("Garlic");
        _toppings.emplace_back("Onion");
        _toppings.emplace_back("Mushrooms");
        _toppings.emplace_back("Red Pepper");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method