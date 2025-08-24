#pragma once

#include <memory>
#include "CeilingFan.hpp"
#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class CeilingFanOffCommand : public Command {
   private:
    std::shared_ptr<CeilingFan> _ceilingFan;

   public:
    explicit CeilingFanOffCommand(std::shared_ptr<CeilingFan> ceilingFan)
        : _ceilingFan(std::move(ceilingFan)) {}

    void execute() const override { _ceilingFan->off(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote