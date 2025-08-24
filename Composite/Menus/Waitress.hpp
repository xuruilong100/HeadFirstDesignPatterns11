#pragma once

#include <memory>
#include "MenuComponent.hpp"

namespace HeadFirstDesignPatterns::Composite::Menus {
class Waitress {
   private:
    std::shared_ptr<MenuComponent> _allMenus;

   public:
    explicit Waitress(std::shared_ptr<MenuComponent> allMenus)
        : _allMenus(std::move(allMenus)) {}
    Waitress(const Waitress&) = delete;
    void operator=(const Waitress&) = delete;

    void printMenu() const { _allMenus->print(); }
};
}  // namespace HeadFirstDesignPatterns::Composite::Menus