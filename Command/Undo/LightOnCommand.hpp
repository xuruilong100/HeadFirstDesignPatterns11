#pragma once

#include <memory>
#include "Command.hpp"
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class LightOnCommand : public Command {
   private:
    std::shared_ptr<Light> _light;

   public:
    explicit LightOnCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {}

    void execute() const override { _light->on(); }

    void undo() const override { _light->off(); }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo