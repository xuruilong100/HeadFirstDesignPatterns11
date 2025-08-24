#pragma once

#include <memory>
#include "Command.hpp"
#include "Light.hpp"

namespace HeadFirstDesignPatterns::Command::Undo {
class DimmerLightOffCommand : public Command {
   private:
    std::shared_ptr<Light> _light;
    mutable int _prevLevel;

   public:
    explicit DimmerLightOffCommand(std::shared_ptr<Light> light)
        : _light(std::move(light)) {
        _prevLevel = _light->getLevel();
    }

    void execute() const override {
        _prevLevel = _light->getLevel();
        _light->off();
    }

    void undo() const override { _light->dim(_prevLevel); }
};
}  // namespace HeadFirstDesignPatterns::Command::Undo