#pragma once

#include <memory>
#include "Command.hpp"
#include "Stereo.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class StereoOnWithCDCommand : public Command {
   private:
    std::shared_ptr<Stereo> _stereo;

   public:
    explicit StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo)
        : _stereo(std::move(stereo)) {}

    void execute() const override {
        _stereo->on();
        _stereo->setCD();
        _stereo->setVolume(11);
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote