#pragma once

#include <string>
#include <thread>
#include "Appliance.hpp"

namespace HeadFirstDesignPatterns::Mediator::AutoHouse {
enum class DayOfWeek {
    Sunday = 0,
    Monday = 1,
    Tuesday = 2,
    Wednsday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6
};

class Calendar : public Appliance {
   public:
    Calendar(Mediator* mediator, unsigned long iterations)
        : Appliance(mediator), _iterations(iterations) {}

    bool isTrashDay(DayOfWeek dayOfWeek) const {
        if (DayOfWeek::Monday == dayOfWeek || DayOfWeek::Friday == dayOfWeek) {
            return true;
        } else {
            return false;
        }
    }

    bool isWeekDay(DayOfWeek dayOfWeek) const {
        if (DayOfWeek::Monday <= dayOfWeek && DayOfWeek::Friday >= dayOfWeek) {
            return true;
        } else {
            return false;
        }
    }

    DayOfWeek today() const { return _today; }

    DayOfWeek today(DayOfWeek dayOfWeek) {
        _today = dayOfWeek;
        return _today;
    }

    void on(unsigned long interval) override {
        _interval = interval;
        if (!_running) {
            _running = true;
            _thread = std::jthread(&Calendar::run, this);
            _thread.join();
        }
    }

    void off() override {
        _interval = 0;
        _running = false;
    }

    void onEvent(unsigned long value) override {
        if (_iterations > 0) {
            _iterations--;
            _mediator->onEvent(this, value);
        } else {
            _interval = 0;  // calendar has expired
        }
    }

    std::string toString() const {
        switch (_today) {
            using enum DayOfWeek;
            case Sunday:
                return "Sunday";
            case Monday:
                return "Monday";
            case Tuesday:
                return "Tuesday";
            case Wednsday:
                return "Wednsday";
            case Thursday:
                return "Thursday";
            case Friday:
                return "Friday";
            case Saturday:
                return "Saturday";
            default:
                return "Error! Invalid day value.";
        }
    }

   private:
    DayOfWeek _today{DayOfWeek::Sunday};
    std::jthread _thread;
    unsigned long _interval{0};  // length of day (in seconds)
    unsigned long _iterations;   // number of day (events)
    bool _running{false};

    void run() {
        _mediator->output("Calendar is on");

        do {
            onEvent(static_cast<unsigned long>(
                _today));  // a calendar event is a new day
            std::this_thread::sleep_for(
                std::chrono::seconds(_interval));  // duration in seconds
            if (_today == DayOfWeek::Saturday) {
                _today = DayOfWeek::Sunday;
            } else {
                auto t = static_cast<int>(_today);
                ++t;
                _today = static_cast<DayOfWeek>(t);
            }
        } while (_running && _interval != 0 && _iterations != 0);

        _mediator->output("Calendar is off");
    }
};
}  // namespace HeadFirstDesignPatterns::Mediator::AutoHouse