#pragma once

namespace HeadFirstDesignPatterns::Command::Undo {
class Command {
   public:
    Command() = default;
    virtual ~Command() = default;

    virtual void execute() = 0;
    virtual void undo() = 0;
};
}  // namespace HeadFirstDesignPatterns::Command::Undo