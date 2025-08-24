#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Command::Remote {
class GarageDoor {
   private:
    std::string _location;

   public:
    explicit GarageDoor(std::string_view location) : _location(location) {}

    void up() const { std::cout << _location << " Door is Up" << std::endl; }

    void down() const {
        std::cout << _location << " Door is Down" << std::endl;
    }

    void stop() const {
        std::cout << _location << " Door is Stopped" << std::endl;
    }

    void lightOn() const {
        std::cout << _location << " light is on" << std::endl;
    }

    void lightOff() const {
        std::cout << _location << " light is off" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote