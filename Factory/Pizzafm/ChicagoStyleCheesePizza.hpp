#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class ChicagoStyleCheesePizza : public Pizza {
   public:
    ChicagoStyleCheesePizza() {
        _name = "Chicago Style Deep Dish Cheese Pizza";
        _dough = "Extra Thick Crust Dough";
        _sauce = "Plum Tomato Sauce";
        _toppings.emplace_back("Shredded Mozzarella Cheese");
    }

    void cut() const override {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method