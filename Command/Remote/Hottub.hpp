#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Command::Remote {
class Hottub {
   private:
    bool _on = false;
    int _temperature = 0;

   public:
    Hottub() = default;

    void on() { _on = true; }

    void off() { _on = false; }

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

    void heat() {
        _temperature = 105;
        std::cout << "Hottub is heating to a steaming 105 degrees" << std::endl;
    }

    void cool() {
        _temperature = 98;
        std::cout << "Hottub is cooling to 98 degrees" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote