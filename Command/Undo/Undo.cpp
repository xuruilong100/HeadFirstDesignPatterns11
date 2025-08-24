#include "CeilingFan.hpp"
#include "CeilingFanHighCommand.hpp"
#include "CeilingFanMediumCommand.hpp"
#include "CeilingFanOffCommand.hpp"
#include "Light.hpp"
#include "LightOffCommand.hpp"
#include "LightOnCommand.hpp"
#include "RemoteControlWithUndo.hpp"

using namespace HeadFirstDesignPatterns::Command::Undo;

int main() {
    auto remoteControl = std::make_shared<RemoteControlWithUndo>();

    auto livingRoomLight = std::make_shared<Light>("Living Room");

    auto livingRoomLightOn = std::make_shared<LightOnCommand>(livingRoomLight);
    auto livingRoomLightOff =
        std::make_shared<LightOffCommand>(livingRoomLight);

    remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(0);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();

    auto ceilingFan = std::make_shared<CeilingFan>("Living Room");

    auto ceilingFanMedium =
        std::make_shared<CeilingFanMediumCommand>(ceilingFan);
    auto ceilingFanHigh = std::make_shared<CeilingFanHighCommand>(ceilingFan);
    auto ceilingFanOff = std::make_shared<CeilingFanOffCommand>(ceilingFan);

    remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
    remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();

    remoteControl->onButtonWasPushed(1);
    std::cout << remoteControl->toString() << std::endl;
    remoteControl->undoButtonWasPushed();

    return EXIT_SUCCESS;
}

// Output:
/*
Living Room light is on
Living Room light is off

------ Remote Control -------
[slot 0] class HeadFirstDesignPatterns::Command::Undo::LightOnCommand    class
HeadFirstDesignPatterns::Command::Undo::LightOffCommand
[slot 1] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 2] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 3] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 4] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 5] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 6] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[undo] class HeadFirstDesignPatterns::Command::Undo::LightOffCommand

Living Room light is on
Living Room light is off
Living Room light is on

------ Remote Control -------
[slot 0] class HeadFirstDesignPatterns::Command::Undo::LightOnCommand    class
HeadFirstDesignPatterns::Command::Undo::LightOffCommand
[slot 1] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 2] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 3] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 4] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 5] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 6] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[undo] class HeadFirstDesignPatterns::Command::Undo::LightOnCommand

Living Room light is off
Living Room ceiling fan is on medium
Living Room ceiling fan is off

------ Remote Control -------
[slot 0] class HeadFirstDesignPatterns::Command::Undo::CeilingFanMediumCommand
class HeadFirstDesignPatterns::Command::Undo::CeilingFanOffCommand
[slot 1] class HeadFirstDesignPatterns::Command::Undo::CeilingFanHighCommand
class HeadFirstDesignPatterns::Command::Undo::CeilingFanOffCommand
[slot 2] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 3] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 4] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 5] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 6] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[undo] class HeadFirstDesignPatterns::Command::Undo::CeilingFanOffCommand

Living Room ceiling fan is on medium
Living Room ceiling fan is on high

------ Remote Control -------
[slot 0] class HeadFirstDesignPatterns::Command::Undo::CeilingFanMediumCommand
class HeadFirstDesignPatterns::Command::Undo::CeilingFanOffCommand
[slot 1] class HeadFirstDesignPatterns::Command::Undo::CeilingFanHighCommand
class HeadFirstDesignPatterns::Command::Undo::CeilingFanOffCommand
[slot 2] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 3] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 4] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 5] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[slot 6] class HeadFirstDesignPatterns::Command::Undo::NoCommand    class
HeadFirstDesignPatterns::Command::Undo::NoCommand
[undo] class HeadFirstDesignPatterns::Command::Undo::CeilingFanHighCommand

Living Room ceiling fan is on medium
*/