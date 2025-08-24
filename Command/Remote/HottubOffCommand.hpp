#pragma once

#include <memory>
#include "Command.hpp"
#include "Hottub.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class HottubOffCommand : public Command {
   private:
    std::shared_ptr<Hottub> _hottub;

   public:
    explicit HottubOffCommand(std::shared_ptr<Hottub> hottub)
        : _hottub(std::move(hottub)) {}

    void execute() const override {
        _hottub->cool();
        _hottub->off();
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote