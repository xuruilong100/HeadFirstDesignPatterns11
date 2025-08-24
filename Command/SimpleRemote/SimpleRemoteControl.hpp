#pragma once

#include <memory>
#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class SimpleRemoteControl {
   private:
    std::shared_ptr<Command> _slot;

   public:
    SimpleRemoteControl() = default;

    void setCommand(std::shared_ptr<Command> command) {
        _slot = std::move(command);
    }

    void buttonWasPressed() const { _slot->execute(); }
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote