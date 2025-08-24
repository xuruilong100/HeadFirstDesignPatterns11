#pragma once

#include <memory>
#include "Command.hpp"
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class LightOffCommand : public Command {
   private:
    std::shared_ptr<Light> _light;

   public:
    explicit LightOffCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() const override { _light->off(); }

    void undo() const override { _light->on(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo