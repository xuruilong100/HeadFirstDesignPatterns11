#pragma once

#include <memory>
#include "Command.hpp"
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class LivingroomLightOffCommand : public Command {
   private:
    std::shared_ptr<Light> _light;

   public:
    explicit LivingroomLightOffCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() const override { _light->off(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote