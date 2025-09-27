#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class NYStyleClamPizza : public Pizza {
   public:
    NYStyleClamPizza() {
        _name = "NY Style Clam Pizza";
        _dough = "Thin Crust Dough";
        _sauce = "Marinara Sauce";
        _toppings.emplace_back("Grated Reggiano Cheese");
        _toppings.emplace_back("Fresh Clams from Long Island Sound");
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method