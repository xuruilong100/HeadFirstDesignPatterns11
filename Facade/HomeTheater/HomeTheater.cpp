#include <iostream>
#include "Amplifier.hpp"
#include "CdPlayer.hpp"
#include "DvdPlayer.hpp"
#include "HomeTheaterFacade.hpp"
#include "PopcornPopper.hpp"
#include "Projector.hpp"
#include "Screen.hpp"
#include "TheaterLights.hpp"
#include "Tuner.hpp"

using namespace HeadFirstDesignPatterns::Facade::HomeTheater;

int main() {
    auto amp = std::make_shared<Amplifier>("Top-O-Line Amplifier");
    auto tuner = std::make_shared<Tuner>("Top-O-Line AM/FM Tuner", amp);
    auto dvd = std::make_shared<DvdPlayer>("Top-O-Line DVD Player", amp);
    auto cd = std::make_shared<CdPlayer>("Top-O-Line CD Player", amp);
    auto projector = std::make_shared<Projector>("Top-O-Line Projector", dvd);
    auto lights = std::make_shared<TheaterLights>("Theater Ceiling Lights");
    auto screen = std::make_shared<Screen>("Theater Screen");
    auto popper = std::make_shared<PopcornPopper>("Popcorn Popper");
    auto homeTheater = std::make_shared<HomeTheaterFacade>(
        amp, tuner, dvd, cd, projector, screen, lights, popper);

    homeTheater->watchMovie("Raiders of the Lost Ark");
    homeTheater->endMovie();

    return EXIT_SUCCESS;
}

// Output:
/*
Get ready to watch a movie...
Popcorn Popper on
Popcorn Popper popping popcorn!
Theater Ceiling Lights dimming to 10%
Theater Screen going down
Top-O-Line Projector on
Top-O-Line Projector in widescreen mode (16x9 aspect ratio)
Top-O-Line Amplifier on
Top-O-Line Amplifier setting DVD player to Top-O-Line DVD Player
Top-O-Line Amplifier surround sound on (5 speakers, 1 subwoofer)
Top-O-Line Amplifier setting volume to 5
Top-O-Line DVD Player on
Top-O-Line DVD Player playing "Raiders of the Lost Ark"
Shutting movie theater down...
Popcorn Popper off
Theater Ceiling Lights on
Theater Screen going up
Top-O-Line Projector off
Top-O-Line Amplifier off
Top-O-Line DVD Player stopped "Raiders of the Lost Ark"
Top-O-Line DVD Player eject
Top-O-Line DVD Player off
*/