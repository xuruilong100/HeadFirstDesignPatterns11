#pragma once

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ClamPizza : public Pizza {
   private:
    std::shared_ptr<PizzaIngredientFactory> _ingredientFactory;

   public:
    explicit ClamPizza(
        std::shared_ptr<PizzaIngredientFactory> ingredientFactory)
        : _ingredientFactory(std::move(ingredientFactory)) {}

    void prepare() override {
        std::cout << "Preparing " << getName() << std::endl;
        _dough = _ingredientFactory->createDough();
        _sauce = _ingredientFactory->createSauce();
        _cheese = _ingredientFactory->createCheese();
        _clam = _ingredientFactory->createClam();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract