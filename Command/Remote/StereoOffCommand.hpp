#pragma once

#include <memory>
#include "Command.hpp"
#include "Stereo.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class StereoOffCommand : public Command {
   private:
    std::shared_ptr<Stereo> _stereo;

   public:
    explicit StereoOffCommand(std::shared_ptr<Stereo> stereo)
        : _stereo(std::move(stereo)) {}

    void execute() const override { _stereo->off(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote