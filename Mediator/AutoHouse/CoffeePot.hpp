#pragma once

#include <thread>
#include "Appliance.hpp"

namespace HeadFirstDesignPatterns::Mediator::AutoHouse {
class CoffeePot : public Appliance {
   public:
    using Appliance::Appliance;

    void off() override {
        _mediator->output("Coffeepot is off");
        _running = false;
    }

    void onEvent(unsigned long value) override {
        _mediator->onEvent(this, value);
    }

    void on(unsigned long value) override {
        _volume = value;
        _mediator->output("Coffeepot is on");

        if (!_running) {
            _running = true;
            _thread = std::jthread(&CoffeePot::run, this);
            _thread.join();
        }
    }

   private:
    unsigned long _volume{0};
    std::jthread _thread;
    bool _running{false};

    void run() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        onEvent(_volume);
    }
};
}  // namespace HeadFirstDesignPatterns::Mediator::AutoHouse