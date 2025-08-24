#pragma once

#include <memory>
#include "Command.hpp"
#include "GarageDoor.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class GarageDoorDownCommand : public Command {
   private:
    std::shared_ptr<GarageDoor> _garageDoor;

   public:
    explicit GarageDoorDownCommand(std::shared_ptr<GarageDoor> garageDoor)
        : _garageDoor(std::move(garageDoor)) {}

    void execute() const override { _garageDoor->down(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote