#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Command::Remote {
class CeilingFan {
   private:
    mutable int _level = LOW;
    std::string _location;

   public:
    static const int HIGH = 2;
    static const int MEDIUM = 1;
    static const int LOW = 0;

    explicit CeilingFan(std::string_view location) : _location(location) {}

    void high() const {
        _level = HIGH;
        std::cout << _location << " ceiling fan is on high" << std::endl;
    }

    void medium() const {
        _level = MEDIUM;
        std::cout << _location << " ceiling fan is on medium" << std::endl;
    }

    void low() const {
        _level = LOW;
        std::cout << _location << " ceiling fan is on low" << std::endl;
    }

    void off() const {
        _level = 0;
        std::cout << _location << " ceiling fan is off" << std::endl;
    }

    int getSpeed() const { return _level; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote