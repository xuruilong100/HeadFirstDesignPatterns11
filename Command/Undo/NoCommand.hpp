#pragma once

#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class NoCommand : public Command {
   public:
    NoCommand() = default;

    void execute() const override {};

    void undo() const override {};
};
}  // namespace HeadFirstDesignPatterns::Command::Undo