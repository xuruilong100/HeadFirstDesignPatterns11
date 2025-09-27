#pragma once

#include "CheesePizza.hpp"
#include "ClamPizza.hpp"
#include "PepperoniPizza.hpp"
#include "Pizza.hpp"
#include "VeggiePizza.hpp"

namespace HeadFirstDesignPatterns::Factory::Simple {
class SimplePizzaFactory {
   public:
    std::shared_ptr<Pizza> createPizza(std::string_view type) const {
        std::shared_ptr<Pizza> pizza;

        if (type.compare("cheese") == 0) {
            pizza = std::make_shared<CheesePizza>();
        } else if (type.compare("pepperoni") == 0) {
            pizza = std::make_shared<PepperoniPizza>();
        } else if (type.compare("clam") == 0) {
            pizza = std::make_shared<ClamPizza>();
        } else if (type.compare("veggie") == 0) {
            pizza = std::make_shared<VeggiePizza>();
        }
        return pizza;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple