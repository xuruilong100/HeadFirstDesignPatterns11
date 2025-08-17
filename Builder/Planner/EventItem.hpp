#pragma once

#include <iostream>
#include <string>
#include "EventComponent.hpp"

namespace HeadFirstDesignPatterns::Builder {
class EventItem : public EventComponent {
   private:
    std::string _name;
    std::string _description;
    double _price;

   public:
    EventItem(std::string_view name, std::string_view description, double price)
        : _name(name), _description(description), _price(price) {}

    std::string getName() const override { return _name; }

    std::string getDescription() const override { return _description; }

    double getPrice() const override { return _price; }

    void print() const override {
        std::cout << "   " << getName();
        std::cout << " , " << getDescription();
        std::cout << "- $" << getPrice() << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Builder