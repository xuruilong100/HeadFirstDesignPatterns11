#pragma once

#include <memory>
#include "CeilingFan.hpp"
#include "Command.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class CeilingFanMediumCommand : public Command {
   private:
    std::shared_ptr<CeilingFan> _ceilingFan;
    int _prevSpeed;

   public:
    explicit CeilingFanMediumCommand(std::shared_ptr<CeilingFan> ceilingFan)
        : _ceilingFan(std::move(ceilingFan)) {
        _prevSpeed = _ceilingFan->getSpeed();
    }

    void execute() override {
        _prevSpeed = _ceilingFan->getSpeed();
        _ceilingFan->medium();
    }

    void undo() override {
        if (_prevSpeed == CeilingFan::HIGH) {
            _ceilingFan->high();
        } else if (_prevSpeed == CeilingFan::MEDIUM) {
            _ceilingFan->medium();
        } else if (_prevSpeed == CeilingFan::LOW) {
            _ceilingFan->low();
        } else if (_prevSpeed == CeilingFan::OFF) {
            _ceilingFan->off();
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo