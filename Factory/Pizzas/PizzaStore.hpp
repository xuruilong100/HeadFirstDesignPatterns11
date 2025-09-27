#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Pizza.hpp"
#include "SimplePizzaFactory.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class PizzaStore {
   private:
    std::shared_ptr<SimplePizzaFactory> _factory;

   public:
    explicit PizzaStore(std::shared_ptr<SimplePizzaFactory> factory)
        : _factory(std::move(factory)) {}

    std::shared_ptr<Pizza> orderPizza(std::string_view type) const {
        auto pizza = _factory->createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple