#pragma once

#include <iostream>
#include <memory>
#include "Builder.hpp"
#include "Day.hpp"
#include "Event.hpp"
#include "EventComponent.hpp"
#include "EventItem.hpp"
#include "Planner.hpp"

namespace HeadFirstDesignPatterns::Builder {
class VacationBuilder : public Builder {
   private:
    std::shared_ptr<Event> _vacation =
        std::make_shared<Event>("Vacation Itinerary", "All events");
    std::shared_ptr<EventComponent> _currentDay;
    std::shared_ptr<EventComponent> _currentEvent;

   public:
    VacationBuilder() {
        std::cout << std::endl
                  << "Welcome to Patternsland Vacation Planner!" << std::endl;
    }

    ~VacationBuilder() {
        std::cout << std::endl
                  << "Goodbye and have a dreamy vacation!" << std::endl;
    }

    void buildDay(const std::chrono::year_month_day& date) override {
        _currentDay = _vacation->add(std::make_shared<Day>(
            std::make_shared<Event>(
                "Day", std::to_string(_vacation->getChildCount() + 1)),
            date));
        _currentEvent = _currentDay;
    }

    void addHotel(const std::string& hotel) override {
        if (hotel.compare(hotelGrandFacadion) == 0) {
            _currentDay->add(std::make_shared<EventItem>(
                "Hotel", hotelGrandFacadion, 399.0));
        } else if (hotel.compare(hotelNostalgicMomento) == 0) {
            _currentDay->add(std::make_shared<EventItem>(
                "Hotel", hotelNostalgicMomento, 199.0));
        }
    }

    void addTickets(const std::string& event) override {
        if (event.compare(ticketPark) == 0) {
            _currentEvent->add(
                std::make_shared<EventItem>("Tickets", ticketPark, 75.0));
        } else if (event.compare(ticketPatternsOnIce) == 0) {
            _currentEvent->add(std::make_shared<EventItem>(
                "Tickets", ticketPatternsOnIce, 45.0));
        } else if (event.compare(ticketCirqueDuPatterns) == 0) {
            _currentEvent->add(std::make_shared<EventItem>(
                "Tickets", ticketCirqueDuPatterns, 60.0));
        }
    }

    void addReservations(const std::string& event) override {
        _currentEvent =
            _currentDay->add(std::make_shared<Event>("Reservation", "Dinner"));
        _currentEvent->add(std::make_shared<EventItem>(event, "", 0.0));
    }

    void addSpecialEvent(const std::string& event) override {
        _currentEvent = _currentDay->add(
            std::make_shared<Event>("Reservation", "Special event"));
        if (event.compare(specialChocolateFactoryTour) == 0) {
            _currentEvent->add(std::make_shared<EventItem>(
                "Tickets", specialChocolateFactoryTour, 45.0));
        } else if (event.compare(specialPizzaFactoryTour) == 0) {
            _currentEvent->add(std::make_shared<EventItem>(
                "Tickets", specialPizzaFactoryTour, 25.0));
        }
    }

    std::shared_ptr<Vacation> getVacationPlanner() override {
        return std::make_shared<Vacation>(_vacation);
    };
};
}  // namespace HeadFirstDesignPatterns::Builder