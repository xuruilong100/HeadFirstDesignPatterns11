#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <typeinfo>
#include "Command.hpp"
#include "NoCommand.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
//
// This is the invoker
//
class RemoteControlWithUndo {
   private:
    static const int SLOTS = 7;
    std::array<std::shared_ptr<Command>, SLOTS> _onCommands;
    std::array<std::shared_ptr<Command>, SLOTS> _offCommands;
    std::shared_ptr<Command> _noCommand = std::make_shared<NoCommand>();
    std::shared_ptr<Command> _undoCommand;

   public:
    RemoteControlWithUndo() {
        for (int i = 0; i < SLOTS; i++) {
            _onCommands[i] = _noCommand;
            _offCommands[i] = _noCommand;
        }
        _undoCommand = _noCommand;
    }

    ~RemoteControlWithUndo() = default;

    void setCommand(int slot,
                    std::shared_ptr<Command> onCommand,
                    std::shared_ptr<Command> offCommand) {
        _onCommands[slot] = onCommand;
        _offCommands[slot] = offCommand;
    }

    void onButtonWasPushed(int slot) {
        _onCommands[slot]->execute();
        _undoCommand = _onCommands[slot];
    }

    void offButtonWasPushed(int slot) {
        _offCommands[slot]->execute();
        _undoCommand = _offCommands[slot];
    }

    void undoButtonWasPushed() const { _undoCommand->undo(); }

    std::string toString() const {
        std::stringstream value;
        value << std::endl << "------ Remote Control -------" << std::endl;
        for (int i = 0; i < SLOTS; i++) {
            value << "[slot " << i << "] ";
            value << typeid(*_onCommands[i]).name();
            value << "    ";
            value << typeid(*_offCommands[i]).name();
            value << std::endl;
        }
        value << "[undo] " << typeid(*_undoCommand).name() << std::endl;

        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo