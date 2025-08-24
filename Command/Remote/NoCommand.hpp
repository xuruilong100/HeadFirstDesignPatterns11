#pragma once

#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class NoCommand : public Command {
   public:
    NoCommand() = default;

    void execute() const override {};
};
}  // namespace HeadFirstDesignPatterns::Command::Remote