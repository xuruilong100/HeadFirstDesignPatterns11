#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class TheaterLights {
   private:
    std::string _description;

   public:
    explicit TheaterLights(std::string_view description)
        : _description(description) {}
    TheaterLights(const TheaterLights&) = delete;
    void operator=(const TheaterLights&) = delete;

    void on() { std::cout << _description << " on" << std::endl; }

    void off() { std::cout << _description << " off" << std::endl; }

    void dim(int level) {
        std::cout << _description << " dimming to " << level << "%"
                  << std::endl;
    }

    std::string toString() { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater