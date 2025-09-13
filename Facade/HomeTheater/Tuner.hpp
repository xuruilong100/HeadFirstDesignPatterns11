#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class Amplifier;

class Tuner {
   private:
    std::string _description;
    std::shared_ptr<Amplifier> _amplifier;
    double _frequency{0.0};

   public:
    Tuner(std::string_view description, std::shared_ptr<Amplifier> amplifier)
        : _description(description), _amplifier(std::move(amplifier)) {}
    Tuner(const Tuner&) = delete;
    void operator=(const Tuner&) = delete;

    void on() { std::cout << _description << " on" << std::endl; }

    void off() { std::cout << _description << " off" << std::endl; }

    void setFrequency(double frequency) {
        std::cout << _description << " setting frequency to " << _frequency
                  << std::endl;
        _frequency = frequency;
    }

    void setAm() {
        std::cout << _description << " setting AM mode" << std::endl;
    }

    void setFm() {
        std::cout << _description << " setting FM mode" << std::endl;
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater