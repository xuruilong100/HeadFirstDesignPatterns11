#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class Amplifier;

class DvdPlayer {
   private:
    std::string _description;
    std::shared_ptr<Amplifier> _amplifier;
    int _currentTrack{0};
    std::string _movie;

   public:
    DvdPlayer(std::string_view description,
              std::shared_ptr<Amplifier> amplifier)
        : _description(description), _amplifier(std::move(amplifier)) {}
    DvdPlayer(const DvdPlayer&) = delete;
    void operator=(const DvdPlayer&) = delete;

    void on() const { std::cout << _description << " on" << std::endl; }

    void off() const { std::cout << _description << " off" << std::endl; }

    void eject() {
        _movie.clear();
        _currentTrack = 0;
        std::cout << _description << " eject" << std::endl;
    }

    void play(std::string_view movie) {
        _movie = movie;
        std::cout << _description << " playing \"" << _movie << "\""
                  << std::endl;
    }

    void play(int track) {
        if (_movie.length() == 0) {
            std::cout << _description << " can't play track " << track
                      << " no dvd inserted" << std::endl;
        } else {
            _currentTrack = track;
            std::cout << _description << " playing track " << track << " of \""
                      << _movie << "\"" << std::endl;
        }
    }

    void stop() {
        _currentTrack = 0;
        std::cout << _description << " stopped \"" << _movie << "\""
                  << std::endl;
    }

    void pause() {
        std::cout << _description << " paused \"" << _movie << "\""
                  << std::endl;
    }

    void setTwoChannelAudio() {
        std::cout << _description << " set two channel audio" << std::endl;
    }

    void setSurroundAudio() {
        std::cout << _description << " set surround audio" << std::endl;
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater