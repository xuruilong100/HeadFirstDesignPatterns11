#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Command::Undo {
class CeilingFan {
   private:
    mutable int _speed = OFF;
    std::string _location;

   public:
    static const int HIGH = 3;
    static const int MEDIUM = 2;
    static const int LOW = 1;
    static const int OFF = 0;

    explicit CeilingFan(std::string_view location) : _location(location) {}

    void high() const {
        _speed = HIGH;
        std::cout << _location << " ceiling fan is on high" << std::endl;
    }

    void medium() const {
        _speed = MEDIUM;
        std::cout << _location << " ceiling fan is on medium" << std::endl;
    }

    void low() const {
        _speed = LOW;
        std::cout << _location << " ceiling fan is on low" << std::endl;
    }

    void off() const {
        _speed = OFF;
        std::cout << _location << " ceiling fan is off" << std::endl;
    }

    int getSpeed() const { return _speed; }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo