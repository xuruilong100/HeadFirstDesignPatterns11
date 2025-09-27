#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class PizzaStore {
   protected:
    PizzaStore() = default;

   public:
    virtual ~PizzaStore() = default;

    virtual std::shared_ptr<Pizza> createPizza(std::string_view type) const = 0;

    std::shared_ptr<Pizza> orderPizza(std::string_view type) const {
        std::shared_ptr<Pizza> pizza(createPizza(type));
        std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method