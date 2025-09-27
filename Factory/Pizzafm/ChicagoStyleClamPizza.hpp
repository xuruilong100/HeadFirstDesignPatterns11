#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class ChicagoStyleClamPizza : public Pizza {
   public:
    ChicagoStyleClamPizza() {
        _name = "Chicago Style Clam Pizza";
        _dough = "Extra Thick Crust Dough";
        _sauce = "Plum Tomato Sauce";
        _toppings.emplace_back("Shredded Mozzarella Cheese");
        _toppings.emplace_back("Frozen Clams from Chesapeake Bay");
    }

    void cut() const override {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method