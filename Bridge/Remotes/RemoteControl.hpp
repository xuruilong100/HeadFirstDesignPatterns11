#pragma once

#include <memory>
#include "TV.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class RemoteControl {
   protected:
    std::shared_ptr<TV> _implementor;

    virtual void setChannel(unsigned int channel) {
        _implementor->tuneChannel(channel);
    }

   public:
    RemoteControl() = default;
    virtual ~RemoteControl() = default;
    RemoteControl(const RemoteControl&) = delete;
    RemoteControl& operator=(const RemoteControl&) = delete;
    RemoteControl(RemoteControl&&) = delete;
    RemoteControl& operator=(RemoteControl&&) = delete;

    virtual void on() { _implementor->on(); }
    virtual void off() { _implementor->off(); }
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes