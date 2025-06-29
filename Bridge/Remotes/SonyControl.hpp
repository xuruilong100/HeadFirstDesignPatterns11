#pragma once

#include "RemoteControl.hpp"
#include "Sony.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class SonyControl : public RemoteControl {
   private:
    unsigned int _currentStation = 0;

   public:
    explicit SonyControl(std::string_view location) {
        _implementor = std::make_shared<Sony>(location);
    }

    void setStation(unsigned int channel) {
        _currentStation = channel;
        setChannel(_currentStation);
    }

    void nextChannel() {
        _currentStation++;
        setChannel(_currentStation);
    }

    void previousChannel() {
        _currentStation--;
        setChannel(_currentStation);
    }
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes