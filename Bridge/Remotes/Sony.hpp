#pragma once

#include <iostream>
#include <string>
#include "TV.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class Sony : public TV {
   private:
    std::string _location;

   public:
    explicit Sony(std::string_view location) : _location(location) {}

    void on() override {
        std::cout << "Sony " << _location << " TV is on" << std::endl;
    }

    void off() override {
        std::cout << "Sony " << _location << " TV is off" << std::endl;
    }

    void tuneChannel(unsigned int channel) override {
        std::cout << "Sony " << _location << " tuned to channel " << channel
                  << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes