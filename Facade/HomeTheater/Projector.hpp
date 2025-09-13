#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "DvdPlayer.hpp"

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class Projector {
   private:
    std::string _description;
    std::shared_ptr<DvdPlayer> _dvdPlayer;

   public:
    Projector(std::string_view description,
              std::shared_ptr<DvdPlayer> dvdPlayer)
        : _description(description), _dvdPlayer(std::move(dvdPlayer)) {}
    Projector(const Projector&) = delete;
    void operator=(const Projector&) = delete;

    void on() { std::cout << _description << " on" << std::endl; }

    void off() { std::cout << _description << " off" << std::endl; }

    void wideScreenMode() {
        std::cout << _description << " in widescreen mode (16x9 aspect ratio)"
                  << std::endl;
    }

    void tvMode() {
        std::cout << _description << " in tv mode (4x3 aspect ratio)"
                  << std::endl;
    }

    std::string toString() { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater