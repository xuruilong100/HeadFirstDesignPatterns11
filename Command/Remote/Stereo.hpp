#pragma once

#include <iostream>
#include <string>

namespace HeadFirstDesignPatterns::Command::Remote {
class Stereo {
   private:
    std::string _location;

   public:
    explicit Stereo(std::string_view location) : _location(location) {}

    void on() const { std::cout << _location << " stereo is on" << std::endl; }

    void off() const {
        std::cout << _location << " stereo is off" << std::endl;
    }

    void setCD() const {
        std::cout << _location << " stereo is set for CD input" << std::endl;
    }

    void setDVD() const {
        std::cout << _location << " stereo is set for DVD input" << std::endl;
    }

    void setRadio() const {
        std::cout << _location << " stereo is set for Radio" << std::endl;
    }

    void setVolume(int volume) const {
        // code to set the volume
        // valid range: 1-11 (after all 11 is better than 10, right?)
        std::cout << _location << " Stereo volume set to " << volume
                  << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote