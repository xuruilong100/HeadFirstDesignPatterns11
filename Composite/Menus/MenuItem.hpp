#pragma once

#include <iostream>
#include <string>
#include "MenuComponent.hpp"

namespace HeadFirstDesignPatterns::Composite::Menus {
class MenuItem : public MenuComponent {
   private:
    std::string _name;
    std::string _description;
    bool _vegetarian;
    double _price;

   public:
    MenuItem(std::string_view name,
             std::string_view description,
             bool vegetarian,
             double price)
        : _name(name),
          _description(description),
          _vegetarian(vegetarian),
          _price(price) {}

    std::string getName() const override { return _name; }

    std::string getDescription() const override { return _description; }

    double getPrice() const override { return _price; }

    bool isVegetarian() const override { return _vegetarian; }

    void print() const override {
        std::cout << "  " << getName();
        if (isVegetarian()) {
            std::cout << "(v)";
        }
        std::cout << ", " << getPrice() << std::endl;
        std::cout << "     -- " << getDescription() << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Composite::Menus