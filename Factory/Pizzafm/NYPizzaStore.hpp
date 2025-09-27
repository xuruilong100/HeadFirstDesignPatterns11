#pragma once

#include "NYStyleCheesePizza.hpp"
#include "NYStyleClamPizza.hpp"
#include "NYStylePepperoniPizza.hpp"
#include "NYStyleVeggiePizza.hpp"
#include "PizzaStore.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class NYPizzaStore : public PizzaStore {
   public:
    std::shared_ptr<Pizza> createPizza(std::string_view type) const override {
        if (type.compare("cheese") == 0) {
            return std::make_shared<NYStyleCheesePizza>();
        } else if (type.compare("veggie") == 0) {
            return std::make_shared<NYStyleVeggiePizza>();
        } else if (type.compare("clam") == 0) {
            return std::make_shared<NYStyleClamPizza>();
        } else if (type.compare("pepperoni") == 0) {
            return std::make_shared<NYStylePepperoniPizza>();
        } else {
            return nullptr;
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method