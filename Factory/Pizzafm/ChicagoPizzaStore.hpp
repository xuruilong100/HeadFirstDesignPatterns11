#pragma once

#include "ChicagoStyleCheesePizza.hpp"
#include "ChicagoStyleClamPizza.hpp"
#include "ChicagoStylePepperoniPizza.hpp"
#include "ChicagoStyleVeggiePizza.hpp"
#include "PizzaStore.hpp"

namespace HeadFirstDesignPatterns::Factory::Method {
class ChicagoPizzaStore : public PizzaStore {
   public:
    std::shared_ptr<Pizza> createPizza(std::string_view type) const override {
        if (type.compare("cheese") == 0) {
            return std::make_shared<ChicagoStyleCheesePizza>();
        } else if (type.compare("veggie") == 0) {
            return std::make_shared<ChicagoStyleVeggiePizza>();
        } else if (type.compare("clam") == 0) {
            return std::make_shared<ChicagoStyleClamPizza>();
        } else if (type.compare("pepperoni") == 0) {
            return std::make_shared<ChicagoStylePepperoniPizza>();
        } else {
            return nullptr;
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method