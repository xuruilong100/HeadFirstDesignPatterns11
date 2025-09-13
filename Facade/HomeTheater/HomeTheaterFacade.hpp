#pragma once

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include "Amplifier.hpp"
#include "CdPlayer.hpp"
#include "DvdPlayer.hpp"
#include "PopcornPopper.hpp"
#include "Projector.hpp"
#include "Screen.hpp"
#include "TheaterLights.hpp"
#include "Tuner.hpp"

namespace HeadFirstDesignPatterns::Facade::HomeTheater {
class HomeTheaterFacade {
   private:
    std::shared_ptr<Amplifier> _amp;
    std::shared_ptr<Tuner> _tuner;
    std::shared_ptr<DvdPlayer> _dvd;
    std::shared_ptr<CdPlayer> _cd;
    std::shared_ptr<Projector> _projector;
    std::shared_ptr<Screen> _screen;
    std::shared_ptr<TheaterLights> _lights;
    std::shared_ptr<PopcornPopper> _popper;

   public:
    HomeTheaterFacade(std::shared_ptr<Amplifier> amp,
                      std::shared_ptr<Tuner> tuner,
                      std::shared_ptr<DvdPlayer> dvd,
                      std::shared_ptr<CdPlayer> cd,
                      std::shared_ptr<Projector> projector,
                      std::shared_ptr<Screen> screen,
                      std::shared_ptr<TheaterLights> lights,
                      std::shared_ptr<PopcornPopper> popper)
        : _amp(std::move(amp)),
          _tuner(std::move(tuner)),
          _dvd(std::move(dvd)),
          _cd(std::move(cd)),
          _projector(std::move(projector)),
          _screen(std::move(screen)),
          _lights(std::move(lights)),
          _popper(std::move(popper)) {}
    HomeTheaterFacade(const HomeTheaterFacade&) = delete;
    void operator=(const HomeTheaterFacade&) = delete;

    void watchMovie(std::string_view movie) {
        std::cout << "Get ready to watch a movie..." << std::endl;
        _popper->on();
        _popper->pop();
        _lights->dim(10);
        _screen->down();
        _projector->on();
        _projector->wideScreenMode();
        _amp->on();
        _amp->setDvd(_dvd);
        _amp->setSurroundSound();
        _amp->setVolume(5);
        _dvd->on();
        _dvd->play(movie);
    }

    void endMovie() {
        std::cout << "Shutting movie theater down..." << std::endl;
        _popper->off();
        _lights->on();
        _screen->up();
        _projector->off();
        _amp->off();
        _dvd->stop();
        _dvd->eject();
        _dvd->off();
    }

    void listenToCd(std::string_view cdTitle) {
        std::cout << "Get ready for an audiopile experence..." << std::endl;
        _lights->on();
        _amp->on();
        _amp->setVolume(5);
        _amp->setCd(_cd);
        _amp->setStereoSound();
        _cd->on();
        _cd->play(cdTitle);
    }

    void endCd() {
        std::cout << "Shutting down CD..." << std::endl;
        _amp->off();
        _amp->setCd(_cd);
        _cd->eject();
        _cd->off();
    }

    void listenToRadio(double frequency) {
        std::cout << "Tuning in the airwaves..." << std::endl;
        _tuner->on();
        _tuner->setFrequency(frequency);
        _amp->on();
        _amp->setVolume(5);
        _amp->setTuner(_tuner);
    }

    void endRadio() {
        std::cout << "Shutting down the tuner..." << std::endl;
        _tuner->off();
        _amp->off();
    }
};
}  // namespace HeadFirstDesignPatterns::Facade::HomeTheater