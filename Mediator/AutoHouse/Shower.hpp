#pragma once

#include "Appliance.hpp"
#include "Mediator.hpp"

namespace HeadFirstDesignPatterns::Mediator::AutoHouse {
class Shower : public Appliance {
   public:
    using Appliance::Appliance;

    void off() override { _mediator->output("Shower is off"); }

    void on(unsigned long value) override { _mediator->output("Shower is on"); }

    void onEvent(unsigned long value) override {
        _mediator->onEvent(this, value);
    }
};
}  // namespace HeadFirstDesignPatterns::Mediator::AutoHouse