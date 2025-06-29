#pragma once

#include <iostream>
#include <string>
#include "TV.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class RCA : public TV {
   private:
    std::string _location;

   public:
    explicit RCA(std::string_view location) : _location(location) {}

    void on() override {
        std::cout << "RCA " << _location << " TV is on" << std::endl;
    }

    void off() override {
        std::cout << "RCA " << _location << " TV is off" << std::endl;
    }

    void tuneChannel(unsigned int channel) override {
        std::cout << "RCA " << _location << " tuned to channel " << channel
                  << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes