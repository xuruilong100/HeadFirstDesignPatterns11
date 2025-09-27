#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "Cheese.hpp"
#include "Clams.hpp"
#include "Dough.hpp"
#include "Pepperoni.hpp"
#include "Sauce.hpp"
#include "Veggies.hpp"

namespace HeadFirstDesignPatterns::Factory::Abstract {
class Pizza {
   private:
    std::string _name;

   protected:
    std::shared_ptr<Dough> _dough;
    std::shared_ptr<Sauce> _sauce;
    std::vector<std::shared_ptr<Veggies>> _veggies;
    std::shared_ptr<Cheese> _cheese;
    std::shared_ptr<Pepperoni> _pepperoni;
    std::shared_ptr<Clams> _clam;

    Pizza() = default;

   public:
    virtual void prepare() = 0;

    Pizza(const Pizza&) = delete;
    void operator=(const Pizza&) = delete;
    virtual ~Pizza() = default;

    virtual void bake() const {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }

    virtual void cut() const {
        std::cout << "Cutting the pizza into diagonal slices" << std::endl;
    }

    virtual void box() const {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }

    void setName(std::string_view name) { _name = name; }

    std::string getName() const { return _name; }

    std::string toString() const {
        std::stringstream value;
        value << "---- " << _name << " ----" << std::endl;

        if (_dough) {
            value << _dough->toString();
            value << std::endl;
        }
        if (_sauce) {
            value << _sauce->toString();
            value << std::endl;
        }
        if (_cheese) {
            value << _cheese->toString();
            value << std::endl;
        }
        if (_clam) {
            value << _clam->toString();
            value << std::endl;
        }
        if (_pepperoni) {
            value << _pepperoni->toString();
            value << std::endl;
        }
        if (!_veggies.empty()) {
            for (const auto& v : _veggies) {
                value << v->toString() << ", ";
            }
            value << std::endl;
        }

        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Abstract