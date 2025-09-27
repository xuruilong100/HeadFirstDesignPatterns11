#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class ClamPizza : public Pizza {
   public:
    ClamPizza() {
        _name = "Clam Pizza";
        _dough = "Thin Crust";
        _sauce = "White garlic Sauce";
        _toppings.emplace_back("Grated parmesan cheese");
        _toppings.emplace_back("Clams");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple