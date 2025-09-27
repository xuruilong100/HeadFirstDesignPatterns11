#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class PepperoniPizza : public Pizza {
   public:
    PepperoniPizza() {
        _name = "Pepperoni Pizza";
        _dough = "Crust";
        _sauce = "Marinara sauce";
        _toppings.emplace_back("Sliced Pepperoni");
        _toppings.emplace_back("Sliced Onion");
        _toppings.emplace_back("Grated parmesan cheese");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple