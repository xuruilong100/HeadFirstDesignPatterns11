#pragma once

#include <memory>
#include "CheesePizza.hpp"
#include "ClamPizza.hpp"
#include "NYPizzaIngredientFactory.hpp"
#include "PepperoniPizza.hpp"
#include "PizzaStore.hpp"
#include "VeggiePizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ChicagoPizzaStore : public PizzaStore {
   public:
    std::shared_ptr<Pizza> createPizza(std::string_view item) const override {
        std::shared_ptr<Pizza> pizza;
        auto ingredientFactory = std::make_shared<NYPizzaIngredientFactory>();

        if (item.compare("cheese") == 0) {
            pizza = std::make_shared<CheesePizza>(ingredientFactory);
            pizza->setName("Chicago Style Cheese Pizza");
        } else if (item.compare("veggie") == 0) {
            pizza = std::make_shared<VeggiePizza>(ingredientFactory);
            pizza->setName("Chicago Style Veggie Pizza");
        } else if (item.compare("clam") == 0) {
            pizza = std::make_shared<ClamPizza>(ingredientFactory);
            pizza->setName("Chicago Style Clam Pizza");
        } else if (item.compare("pepperoni") == 0) {
            pizza = std::make_shared<PepperoniPizza>(ingredientFactory);
            pizza->setName("Chicago Style Pepperoni Pizza");
        }
        return pizza;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract