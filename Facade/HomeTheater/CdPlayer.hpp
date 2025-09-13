#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class Amplifier;

class CdPlayer {
   private:
    std::string _description;
    std::shared_ptr<Amplifier> _amplifier;
    std::string _title;
    int _currentTrack{0};

   public:
    CdPlayer(std::string description, std::shared_ptr<Amplifier> amplifier)
        : _description(description), _amplifier(std::move(amplifier)) {}
    CdPlayer(const CdPlayer&) = delete;
    void operator=(const CdPlayer&) = delete;

    void on() const { std::cout << _description << " on" << std::endl; }

    void off() const { std::cout << _description << " off" << std::endl; }

    void eject() {
        _title.clear();
        _currentTrack = 0;
        std::cout << _description << " eject" << std::endl;
    }

    void play(std::string_view title) {
        _title = title;
        std::cout << _description << " playing \"" << _title << "\""
                  << std::endl;
    }

    void play(int track) {
        if (_title.empty()) {
            std::cout << _description << " can't play track " << _currentTrack
                      << ", no cd inserted" << std::endl;
        } else {
            _currentTrack = track;
            std::cout << _description << " playing track " << _currentTrack
                      << std::endl;
        }
    }

    void stop() {
        _currentTrack = 0;
        std::cout << _description << " stopped" << std::endl;
    }

    void pause() {
        std::cout << _description << " paused \"" << _title << "\""
                  << std::endl;
    }

    std::string toString() const { return _description; }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater