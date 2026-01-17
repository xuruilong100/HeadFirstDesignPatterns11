#pragma once

#include "Mediator.hpp"
#include <iostream>
#include "Alarm.hpp"
#include "Calendar.hpp"
#include "CoffeePot.hpp"
#include "Shower.hpp"
#include "Sprinkler.hpp"
#include "WeatherStation.hpp"

using namespace HeadFirstDesignPatterns::Mediator::AutoHouse;

Mediator::Mediator(unsigned long iterations) : _iterations(iterations) {
    output("Auto-house is on", true, true);

    _alarm = std::make_shared<Alarm>(this);
    _calendar = std::make_shared<Calendar>(this, _iterations);
    _coffeePot = std::make_shared<CoffeePot>(this);
    _sprinkler = std::make_shared<Sprinkler>(this);
    _shower = std::make_shared<Shower>(this);
    _weatherStation = std::make_shared<WeatherStation>(this);
}

Mediator::~Mediator() {
    off();
    output("Auto-house is off", true, true);
}

void Mediator::on(unsigned long interval) {
    _interval = interval;
    _calendar->on(_interval);
}
void Mediator::off() {
    _calendar->off();
    _alarm->off();
    _coffeePot->off();
    _sprinkler->off();
    _shower->off();
    _weatherStation->off();
}
void Mediator::onEvent(const Appliance* appliance, unsigned long value) const {
    if (appliance == _calendar.get()) {
        output("Calendar -- It's " + _calendar->toString(), true, true);
        if (true == _calendar->isTrashDay(static_cast<DayOfWeek>(value))) {
            output("Calendar -- It's trash day, setting the alarm (early)");
            _alarm->on(_interval / 4);  // set alarm (early) on trash day
        } else if (true ==
                   _calendar->isWeekDay(static_cast<DayOfWeek>(value))) {
            output("Calendar -- It's a work day, setting the alarm");
            _alarm->on(_interval / 3);  // set alarm on work day
        } else {
            output("Calendar -- It's the weekend (no alarm)");
            _alarm->off();
        }

        if (_weatherStation->isRainning()) {
            output("Weather station -- It's duck weather (raining)");
        } else {
            output("Weather station -- It's nice weather (not raining)");
            _sprinkler->on(5);
        }
    } else if (appliance == _alarm.get()) {
        output("Alarm -- Buzzzzz!");
        if (_calendar->isWeekDay(_calendar->today())) {
            _coffeePot->on(2);
            _sprinkler->off();
            _shower->on(100);

            std::this_thread::sleep_for(std::chrono::seconds(2));

            _shower->off();
            _alarm->off();
        }
    } else if (appliance == _coffeePot.get()) {
        output("Coffeepot -- finished");
        _coffeePot->off();
    } else if (appliance == _sprinkler.get()) {
        output("Sprinkler -- finished");
        _sprinkler->off();
    }
}

void Mediator::output(std::string_view value, bool before, bool after) const {
    std::lock_guard<std::mutex> locker(_mutex);

    if (true == before) {
        std::cout << std::endl;
    }

    std::cout << value;

    if (true == after) {
        std::cout << std::endl;
    }
}