#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class CheesePizza : public Pizza {
   public:
    CheesePizza() {
        _name = "Cheese Pizza";
        _dough = "Regular Crust";
        _sauce = "Marinara Pizza Sauce";
        _toppings.emplace_back("Shredded Mozzarella");
        _toppings.emplace_back("Parmesan");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple