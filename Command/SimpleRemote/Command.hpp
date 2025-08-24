#pragma once

namespace HeadFirstDesignPatterns::Command::SimpleRemote {
class Command {
   public:
    Command() = default;
    virtual ~Command() = default;
    virtual void execute() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Command::SimpleRemote