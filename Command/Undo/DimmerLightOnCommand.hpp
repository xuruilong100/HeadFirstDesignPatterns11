#pragma once

#include <memory>
#include "Command.hpp"
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class DimmerLightOnCommand : public Command {
   private:
    std::shared_ptr<Light> _light;
    int _prevLevel;

   public:
    explicit DimmerLightOnCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {
        _prevLevel = _light->getLevel();
    }

    void execute() override {
        _prevLevel = _light->getLevel();
        _light->dim(75);
    }

    void undo() override { _light->dim(_prevLevel); }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo