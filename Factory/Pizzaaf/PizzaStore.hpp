#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "Pizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class PizzaStore {
   protected:
    PizzaStore() = default;

   public:
    virtual ~PizzaStore() = default;

    std::shared_ptr<Pizza> orderPizza(std::string_view type) const {
        auto pizza = createPizza(type);
        std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

    virtual std::shared_ptr<Pizza> createPizza(std::string_view type) const = 0;
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract