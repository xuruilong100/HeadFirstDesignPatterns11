#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Command::Undo {
class Light {
   private:
    std::string _location;
    int _level = 0;

   public:
    explicit Light(std::string_view location) : _location(location) {}

    void on() {
        _level = 100;
        std::cout << _location << " light is on" << std::endl;
    }

    void off() {
        _level = 0;
        std::cout << _location << " light is off" << std::endl;
    }

    void dim(int level) {
        _level = level;
        if (_level == 0) {
            off();
        } else {
            std::cout << "Light is dimmed to " << _level << "%" << std::endl;
        }
    }

    int getLevel() const { return _level; }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo