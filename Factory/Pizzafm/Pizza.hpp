#pragma once

#include <iostream>
#include <list>
#include <sstream>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Method {
class Pizza {
   protected:
    std::string _name;
    std::string _dough;
    std::string _sauce;
    std::list<std::string> _toppings;

   protected:
    Pizza() = default;

   public:
    virtual ~Pizza() = default;
    Pizza(const Pizza&) = delete;
    void operator=(const Pizza&) = delete;

    virtual void prepare() const {
        std::cout << "Preparing " << _name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: " << std::endl;
        for (const auto& top : _toppings) {
            std::cout << "   " << top << std::endl;
        }
    }

    virtual void bake() const {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }

    virtual void cut() const {
        std::cout << "Cutting the pizza into diagonal slices" << std::endl;
    }

    virtual void box() const {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }

    std::string getName() const { return _name; }

    std::string toString() const {
        // code to display pizza name and ingredients
        std::stringstream value;
        value << "---- " << _name << " ----" << std::endl;
        value << _dough << std::endl;
        value << _sauce << std::endl;
        for (const auto& top : _toppings) {
            value << top << std::endl;
        }
        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Method