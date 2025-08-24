#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Command::Remote {
class Hottub {
   private:
    mutable bool _on;
    mutable int _temperature;

   public:
    Hottub() : _on(false), _temperature(0) {}

    void on() const { _on = true; }

    void off() const { _on = false; }

    void bubblesOn() const {
        if (_on) {
            std::cout << "Hottub is bubbling!" << std::endl;
        }
    }

    void bubblesOff() const {
        if (_on) {
            std::cout << "Hottub is not bubbling" << std::endl;
        }
    }

    void jetsOn() const {
        if (_on) {
            std::cout << "Hottub jets are on" << std::endl;
        }
    }

    void jetsOff() const {
        if (_on) {
            std::cout << "Hottub jets are off" << std::endl;
        }
    }

    void setTemperature(int temperature) { _temperature = temperature; }

    void heat() const {
        _temperature = 105;
        std::cout << "Hottub is heating to a steaming 105 degrees" << std::endl;
    }

    void cool() const {
        _temperature = 98;
        std::cout << "Hottub is cooling to 98 degrees" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote