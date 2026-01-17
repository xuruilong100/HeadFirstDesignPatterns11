#pragma once

#include <chrono>
#include <thread>
#include "Appliance.hpp"
#include "Mediator.hpp"

namespace HeadFirstDesignPatterns::Mediator::AutoHouse {
class Alarm : public Appliance {
   public:
    using Appliance::Appliance;

    void onEvent(unsigned long value) override {
        _mediator->onEvent(this, value);
    }

    void off() override {
        if (_interval != 0) {
            _mediator->output("Alarm is off");
        }
        _interval = 0;
    }

    void on(unsigned long value) override {
        if (_interval == 0) {
            _mediator->output("Alarm is on");
            _thread = std::jthread(&Alarm::run, this);
            //_thread.join();
        }
        _interval = value;
    }

   private:
    std::jthread _thread;
    unsigned long _interval{0};

    void run() {
        std::this_thread::sleep_for(std::chrono::seconds(_interval));
        if (_interval != 0) {  // check if still on
            onEvent(0);
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Mediator::AutoHouse