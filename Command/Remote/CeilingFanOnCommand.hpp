#pragma once

#include <memory>
#include "CeilingFan.hpp"
#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class CeilingFanOnCommand : public Command {
   private:
    std::shared_ptr<CeilingFan> _ceilingFan;

   public:
    explicit CeilingFanOnCommand(std::shared_ptr<CeilingFan> ceilingFan)
        : _ceilingFan(std::move(ceilingFan)) {}

    void execute() const override { _ceilingFan->high(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote