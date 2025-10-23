#pragma once

#include <iostream>
#include <list>
#include <sstream>
#include <string>

namespace HeadFirstDesignPatterns::Factory::Simple {
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

    std::string getName() const { return _name; }

    virtual void prepare() const {
        std::cout << "Preparing " << _name.c_str() << std::endl;
    }

    virtual void bake() const {
        std::cout << "Baking " << _name.c_str() << std::endl;
    }

    virtual void cut() const {
        std::cout << "Cutting " << _name.c_str() << std::endl;
    }

    virtual void box() const {
        std::cout << "Boxing " << _name.c_str() << std::endl;
    }

    std::string toString() const {
        // code to display pizza name and ingredients
        std::stringstream value;
        value << "---- " << _name.c_str() << " ----" << std::endl;
        value << _dough.c_str() << std::endl;
        value << _sauce.c_str() << std::endl;
        for (const auto& top : _toppings) {
            value << top << std::endl;
        }
        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Simple