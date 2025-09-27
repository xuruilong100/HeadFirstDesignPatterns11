#pragma once

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class CheesePizza : public Pizza {
   private:
    std::shared_ptr<PizzaIngredientFactory> _ingredientFactory;

   public:
    explicit CheesePizza(
        std::shared_ptr<PizzaIngredientFactory> ingredientFactory)
        : _ingredientFactory(std::move(ingredientFactory)) {}

    void prepare() override {
        std::cout << "Preparing " << getName() << std::endl;
        _dough = _ingredientFactory->createDough();
        _sauce = _ingredientFactory->createSauce();
        _cheese = _ingredientFactory->createCheese();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract