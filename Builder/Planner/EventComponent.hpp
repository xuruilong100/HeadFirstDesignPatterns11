#pragma once

#include <memory>
#include <stdexcept>

namespace HeadFirstDesignPatterns::Builder {
class EventComponent {
   public:
    EventComponent() = default;
    EventComponent(const EventComponent&) = delete;
    void operator=(const EventComponent&) = delete;

    virtual ~EventComponent() = default;

    virtual std::shared_ptr<EventComponent> add(
        const std::shared_ptr<EventComponent>& event) {
        throw std::runtime_error("Unsupported operation");
    }

    virtual void remove(const std::shared_ptr<EventComponent>& event) {
        throw std::runtime_error("Unsupported operation");
    }

    virtual const std::shared_ptr<EventComponent>& getChild(int i) const {
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

    virtual void print() const {
        throw std::runtime_error("Unsupported operation");
    }
};
}  // namespace HeadFirstDesignPatterns::Builder