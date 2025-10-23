#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Command::Remote {
class CeilingFan {
   private:
    int _level = LOW;
    std::string _location;

   public:
    static const int HIGH = 2;
    static const int MEDIUM = 1;
    static const int LOW = 0;

    explicit CeilingFan(std::string_view location) : _location(location) {}

    void high() {
        _level = HIGH;
        std::cout << _location << " ceiling fan is on high" << std::endl;
    }

    void medium() {
        _level = MEDIUM;
        std::cout << _location << " ceiling fan is on medium" << std::endl;
    }

    void low() {
        _level = LOW;
        std::cout << _location << " ceiling fan is on low" << std::endl;
    }

    void off() {
        _level = 0;
        std::cout << _location << " ceiling fan is off" << std::endl;
    }

    int getSpeed() const { return _level; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote