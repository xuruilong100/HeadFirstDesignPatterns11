#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "MenuComponent.hpp"

namespace HeadFirstDesignPatterns::Composite::Menus {
class Menu : public MenuComponent {
   private:
    std::string _name;
    std::string _description;
    std::vector<std::shared_ptr<MenuComponent>> _menuComponents;

   public:
    Menu(std::string_view name, std::string_view description)
        : _name(name), _description(description) {}

    void add(const std::shared_ptr<MenuComponent>& menuComponent) override {
        _menuComponents.push_back(menuComponent);
    }

    void remove(const std::shared_ptr<MenuComponent>& menuComponent) override {
        _menuComponents.erase(std::remove(_menuComponents.begin(),
                                          _menuComponents.end(), menuComponent),
                              _menuComponents.end());
    }

    const std::shared_ptr<MenuComponent>& getChild(int i) const override {
        return _menuComponents[i];
    }

    std::string getName() const override { return _name; }

    std::string getDescription() const override { return _description; }

    void print() const override {
        std::cout << std::endl << getName();
        std::cout << ", " << getDescription() << std::endl;
        std::cout << "---------------------" << std::endl;

        auto iterator = _menuComponents.begin();
        while (iterator != _menuComponents.end()) {
            auto menuComponent = *iterator++;
            menuComponent->print();
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Composite::Menus