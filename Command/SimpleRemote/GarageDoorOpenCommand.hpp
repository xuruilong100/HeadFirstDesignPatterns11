#pragma once

#include <memory>
#include "Command.hpp"
#include "GarageDoor.hpp"

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class GarageDoorOpenCommand : public Command {
   private:
    std::shared_ptr<GarageDoor> _garageDoor;

   public:
    explicit GarageDoorOpenCommand(std::shared_ptr<GarageDoor> garageDoor)
        : _garageDoor(std::move(garageDoor)) {}

    void execute() const override { _garageDoor->up(); }
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote