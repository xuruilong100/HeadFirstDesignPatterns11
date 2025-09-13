#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class PopcornPopper {
   private:
    std::string _description;

   public:
    explicit PopcornPopper(std::string_view description)
        : _description(description) {}
    PopcornPopper(const PopcornPopper&) = delete;
    void operator=(const PopcornPopper&) = delete;

    void on() const { std::cout << _description << " on" << std::endl; }

    void off() const { std::cout << _description << " off" << std::endl; }

    void pop() const {
        std::cout << _description << " popping popcorn!" << std::endl;
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater