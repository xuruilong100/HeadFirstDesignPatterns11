#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class Light {
   public:
    Light() = default;

    void on() const { std::cout << "Light is on" << std::endl; }
    void off() const { std::cout << "Light is off" << std::endl; }
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote