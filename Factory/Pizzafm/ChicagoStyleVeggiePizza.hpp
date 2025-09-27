#pragma once

#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class ChicagoStyleVeggiePizza : public Pizza {
   public:
    ChicagoStyleVeggiePizza() {
        _name = "Chicago Deep Dish Veggie Pizza";
        _dough = "Extra Thick Crust Dough";
        _sauce = "Plum Tomato Sauce";
        _toppings.emplace_back("Shredded Mozzarella Cheese");
        _toppings.emplace_back("Black Olives");
        _toppings.emplace_back("Spinach");
        _toppings.emplace_back("Eggplant");
    }

    void cut() const override {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method