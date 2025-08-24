#pragma once

#include <memory>
#include "Command.hpp"
#include "GarageDoor.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class GarageDoorUpCommand : public Command {
   private:
    std::shared_ptr<GarageDoor> _garageDoor;

   public:
    explicit GarageDoorUpCommand(std::shared_ptr<GarageDoor> garageDoor)
        : _garageDoor(std::move(garageDoor)) {}

    void execute() const override { _garageDoor->up(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote