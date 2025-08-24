#include "GarageDoor.hpp"
#include "GarageDoorOpenCommand.hpp"
#include "Light.hpp"
#include "LightOnCommand.hpp"
#include "SimpleRemoteControl.hpp"

using namespace HeadFirstDesignPatterns::Command::SimpleRemote;

int main() {
    auto remote = std::make_shared<SimpleRemoteControl>();
    auto light = std::make_shared<Light>();
    auto garageDoor = std::make_shared<GarageDoor>();
    auto lightOn = std::make_shared<LightOnCommand>(light);
    auto garageOpen = std::make_shared<GarageDoorOpenCommand>(garageDoor);

    remote->setCommand(lightOn);
    remote->buttonWasPressed();
    remote->setCommand(garageOpen);
    remote->buttonWasPressed();

    return EXIT_SUCCESS;
}

// Output:
/*
Light is on
Garage Door is Open
*/