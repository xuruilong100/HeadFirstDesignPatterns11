#pragma once

#include <cstdlib>
#include "Appliance.hpp"
#include "Mediator.hpp"

namespace HeadFirstDesignPatterns::Mediator::AutoHouse {
class WeatherStation : public Appliance {
   public:
    using Appliance::Appliance;

    void off() override { _mediator->output("Weather station is off"); }

    void on(unsigned long value) override {
        srand(42);
        _mediator->output("Weather station is on");
    }

    void onEvent(unsigned long value) override {
        _mediator->onEvent(this, value);
    }

    bool isRainning() const { return (rand() % 100) % 2 == 0; }
};
}  // namespace HeadFirstDesignPatterns::Mediator::AutoHouse