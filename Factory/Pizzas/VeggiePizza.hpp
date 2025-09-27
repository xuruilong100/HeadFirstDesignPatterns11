#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class VeggiePizza : public Pizza {
   public:
    VeggiePizza() {
        _name = "Veggie Pizza";
        _dough = "Crust";
        _sauce = "Marinara Sauce";
        _toppings.emplace_back("Fresh Mozzarella");
        _toppings.emplace_back("Grated Parmesan");
        _toppings.emplace_back("Diced onion");
        _toppings.emplace_back("Sliced mushrooms");
        _toppings.emplace_back("Sliced red pepper");
        _toppings.emplace_back("Sliced black olives");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple