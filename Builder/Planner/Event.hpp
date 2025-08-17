#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "EventComponent.hpp"

namespace HeadFirstDesignPatterns::Builder {
class Event : public EventComponent {
   private:
    std::vector<std::shared_ptr<EventComponent>> _events;
    std::string _name;
    std::string _description;

   public:
    Event(std::string_view name, std::string_view description)
        : _name(name), _description(description) {}

    ~Event() = default;

    std::shared_ptr<EventComponent> add(
        const std::shared_ptr<EventComponent>& event) override {
        _events.push_back(event);
        return event;
    }

    void remove(const std::shared_ptr<EventComponent>& event) override {
        std::remove(_events.begin(), _events.end(), event);
    }

    int getChildCount() const { return static_cast<int>(_events.size()); }

    const std::shared_ptr<EventComponent>& getChild(int i) const override {
        return _events[i];
    }

    std::string getDescription() const override { return _description; }

    std::string getName() const override { return _name; }

    void print() const override {
        std::cout << "  " << getName();
        std::cout << ", " << getDescription() << std::endl;

        auto iterator = _events.begin();
        while (iterator != _events.end()) {
            (*iterator)->print();
            ++iterator;
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Builder