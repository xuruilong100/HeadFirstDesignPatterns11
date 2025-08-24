#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Command::Remote {
class Light {
   private:
    std::string _location;

   public:
    explicit Light(std::string_view location) : _location(location) {}

    void on() const { std::cout << _location << " light is on" << std::endl; }

    void off() const { std::cout << _location << " light is off" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote