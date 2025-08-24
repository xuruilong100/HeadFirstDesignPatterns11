#pragma once

#include <array>
#include <cassert>
#include <memory>
#include <sstream>
#include <string>
#include <typeinfo>
#include "Command.hpp"
#include "NoCommand.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
//
// This is the invoker
//
class RemoteControl {
   private:
    static const int SLOTS = 7;
    std::array<std::shared_ptr<Command>, SLOTS> _onCommands;
    std::array<std::shared_ptr<Command>, SLOTS> _offCommands;
    std::shared_ptr<Command> _noCommand;

   public:
    RemoteControl() {
        _noCommand = std::make_shared<NoCommand>();
        for (int i = 0; i < SLOTS; i++) {
            _onCommands[i] = _noCommand;
            _offCommands[i] = _noCommand;
        }
    }

    RemoteControl(const RemoteControl&) = delete;
    void operator=(const RemoteControl&) = delete;

    ~RemoteControl() = default;

    void setCommand(int slot,
                    std::shared_ptr<Command> onCommand,
                    std::shared_ptr<Command> offCommand) {
        _onCommands[slot] = onCommand;
        _offCommands[slot] = offCommand;
    }

    void onButtonWasPushed(int slot) const { _onCommands[slot]->execute(); }

    void offButtonWasPushed(int slot) const { _offCommands[slot]->execute(); }

    std::string toString() const {
        std::stringstream value;
        value << "\n------ Remote Control -------\n" << std::endl;
        for (int i = 0; i < SLOTS; i++) {
            value << "[slot " << i << "] ";
            value << typeid(*(_onCommands[i])).name();
            value << "    ";
            value << typeid(*(_offCommands[i])).name();
            value << std::endl;
        }
        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote