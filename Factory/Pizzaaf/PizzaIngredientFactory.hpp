#pragma once

#include <memory>
#include <vector>
#include "Cheese.hpp"
#include "Clams.hpp"
#include "Dough.hpp"
#include "Pepperoni.hpp"
#include "Sauce.hpp"
#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class PizzaIngredientFactory {
   public:
    PizzaIngredientFactory() = default;
    virtual ~PizzaIngredientFactory() = default;

    virtual std::shared_ptr<Dough> createDough() const = 0;
    virtual std::shared_ptr<Sauce> createSauce() const = 0;
    virtual std::shared_ptr<Cheese> createCheese() const = 0;
    virtual std::vector<std::shared_ptr<Veggies>> createVeggies() const = 0;
    virtual std::shared_ptr<Pepperoni> createPepperoni() const = 0;
    virtual std::shared_ptr<Clams> createClam() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract