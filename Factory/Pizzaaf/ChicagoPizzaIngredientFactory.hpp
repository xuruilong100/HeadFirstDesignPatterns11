#pragma once

#include <vector>
#include "BlackOlives.hpp"
#include "Eggplant.hpp"
#include "FrozenClams.hpp"
#include "MozzarellaCheese.hpp"
#include "PizzaIngredientFactory.hpp"
#include "PlumTomatoSauce.hpp"
#include "SlicedPepperoni.hpp"
#include "Spinach.hpp"
#include "ThickCrustDough.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
   public:
    std::shared_ptr<Dough> createDough() const override {
        return std::make_shared<ThickCrustDough>();
    }

    std::shared_ptr<Sauce> createSauce() const override {
        return std::make_shared<PlumTomatoSauce>();
    }

    std::shared_ptr<Cheese> createCheese() const override {
        return std::make_shared<MozzarellaCheese>();
    }

    std::vector<std::shared_ptr<Veggies>> createVeggies() const override {
        std::vector<std::shared_ptr<Veggies>> value;
        value.push_back(std::make_shared<BlackOlives>());
        value.push_back(std::make_shared<Spinach>());
        value.push_back(std::make_shared<Eggplant>());
        return value;
    }

    std::shared_ptr<Pepperoni> createPepperoni() const override {
        return std::make_shared<SlicedPepperoni>();
    }

    std::shared_ptr<Clams> createClam() const override {
        return std::make_shared<FrozenClams>();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract