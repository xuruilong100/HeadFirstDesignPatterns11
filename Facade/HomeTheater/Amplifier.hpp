#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "CdPlayer.hpp"
#include "DvdPlayer.hpp"
#include "Tuner.hpp"

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class Amplifier {
   private:
    std::string _description;
    std::shared_ptr<Tuner> _tuner;
    std::shared_ptr<DvdPlayer> _dvd;
    std::shared_ptr<CdPlayer> _cd;

   public:
    explicit Amplifier(std::string_view description)
        : _description(description) {}
    Amplifier(const Amplifier&) = delete;
    void operator=(const Amplifier&) = delete;

    void on() const { std::cout << _description << " on" << std::endl; }

    void off() const { std::cout << _description << " off" << std::endl; }

    void setStereoSound() {
        std::cout << _description << " stereo mode on" << std::endl;
    }

    void setSurroundSound() {
        std::cout << _description
                  << " surround sound on (5 speakers, 1 subwoofer)"
                  << std::endl;
    }

    void setVolume(int level) {
        std::cout << _description << " setting volume to " << level
                  << std::endl;
    }

    void setTuner(std::shared_ptr<Tuner> tuner) {
        std::cout << _description << " setting tuner to " << tuner->toString()
                  << std::endl;
        _tuner = std::move(tuner);
    }

    void setDvd(std::shared_ptr<DvdPlayer> dvd) {
        std::cout << _description << " setting DVD player to "
                  << dvd->toString() << std::endl;
        _dvd = std::move(dvd);
    }

    void setCd(std::shared_ptr<CdPlayer> cd) {
        std::cout << _description << " setting CD player to " << cd->toString()
                  << std::endl;
        _cd = std::move(cd);
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater