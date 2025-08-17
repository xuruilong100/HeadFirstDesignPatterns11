#pragma once

#include <chrono>
#include <iostream>
#include "Event.hpp"
#include "EventComponent.hpp"

namespace HeadFirstDesignPatterns::Builder {
//
// Day 'decorates' and 'Event Component' with a 'date'
//
class Day : public EventComponent {
   private:
    std::shared_ptr<Event> _event;
    std::chrono::year_month_day _date;

   public:
    Day(std::shared_ptr<Event> event, std::chrono::year_month_day date)
        : _event(std::move(event)), _date(std::move(date)) {}

    ~Day() = default;

    std::shared_ptr<EventComponent> add(
        const std::shared_ptr<EventComponent>& event) override {
        return _event->add(event);
    }

    void print() const override {
        std::cout << _date << " : ";
        _event->print();
    }
};
}  // namespace HeadFirstDesignPatterns::Builder