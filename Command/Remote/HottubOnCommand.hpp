#pragma once

#include <memory>
#include "Command.hpp"
#include "Hottub.hpp"

namespace HeadFirstDesignPatterns::Command::Remote {
class HottubOnCommand : public Command {
   private:
    std::shared_ptr<Hottub> _hottub;

   public:
    explicit HottubOnCommand(std::shared_ptr<Hottub> hottub)
        : _hottub(std::move(hottub)) {}

    void execute() const override {
        _hottub->on();
        _hottub->heat();
        _hottub->bubblesOn();
    }
};
}  // namespace HeadFirstDesignPatterns::Command::Remote