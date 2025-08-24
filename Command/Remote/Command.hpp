#pragma once

namespace HeadFirstDesignPatterns::Command::Remote {
class Command {
   protected:
    Command() = default;

   public:
    Command(const Command&) = delete;
    void operator=(const Command&) = delete;

    virtual ~Command() = default;

    virtual void execute() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Command::Remote