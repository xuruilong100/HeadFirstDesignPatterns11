#pragma once

#include <vector>
#include "FreshClams.hpp"
#include "Garlic.hpp"
#include "MarinaraSauce.hpp"
#include "Mushroom.hpp"
#include "Onion.hpp"
#include "PizzaIngredientFactory.hpp"
#include "RedPepper.hpp"
#include "ReggianoCheese.hpp"
#include "SlicedPepperoni.hpp"
#include "ThinCrustDough.hpp"
#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class NYPizzaIngredientFactory : public PizzaIngredientFactory {
   public:
    std::shared_ptr<Dough> createDough() const override {
        return std::make_shared<ThinCrustDough>();
    }

    std::shared_ptr<Sauce> createSauce() const override {
        return std::make_shared<MarinaraSauce>();
    }

    std::shared_ptr<Cheese> createCheese() const override {
        return std::make_shared<ReggianoCheese>();
    }

    std::vector<std::shared_ptr<Veggies>> createVeggies() const override {
        std::vector<std::shared_ptr<Veggies>> veggies;
        veggies.push_back(std::make_shared<Garlic>());
        veggies.push_back(std::make_shared<Onion>());
        veggies.push_back(std::make_shared<Mushroom>());
        veggies.push_back(std::make_shared<RedPepper>());
        return veggies;
    }

    std::shared_ptr<Pepperoni> createPepperoni() const override {
        return std::make_shared<SlicedPepperoni>();
    }

    std::shared_ptr<Clams> createClam() const override {
        return std::make_shared<FreshClams>();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract