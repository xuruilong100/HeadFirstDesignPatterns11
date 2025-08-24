#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace HeadFirstDesignPatterns::Composite::Menus {
class MenuComponent {
   private:
   public:
    MenuComponent() = default;
    MenuComponent(const MenuComponent&) = delete;
    void operator=(const MenuComponent&) = delete;
    virtual ~MenuComponent() = default;

    virtual void add(const std::shared_ptr<MenuComponent>& menuComponent) {
        throw std::runtime_error("Unsupported operation");
    }

    virtual void remove(const std::shared_ptr<MenuComponent>& menuComponent) {
        throw std::runtime_error("Unsupported operation");
    }

    virtual const std::shared_ptr<MenuComponent>& getChild(int i) const {
        throw std::runtime_error("Unsupported operation");
    }

    virtual std::string getName() const {
        throw std::runtime_error("Unsupported operation");
    }

    virtual std::string getDescription() const {
        throw std::runtime_error("Unsupported operation");
    }

    virtual double getPrice() const {
        throw std::runtime_error("Unsupported operation");
    }

    virtual bool isVegetarian() const {
        throw std::runtime_error("Unsupported operation");
    }

    virtual void print() const {
        throw std::runtime_error("Unsupported operation");
    }
};
}  // namespace HeadFirstDesignPatterns::Composite::Menus