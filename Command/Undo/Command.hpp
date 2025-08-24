#pragma once

namespace HeadFirstDesignPatterns::Command::Undo {
class Command {
   public:
    Command() = default;
    virtual ~Command() = default;

    virtual void execute() const = 0;
    virtual void undo() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Command::Undo