#pragma once

#include "RCA.hpp"
#include "RemoteControl.hpp"

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class RCAControl : public RemoteControl {
   private:
    unsigned int _currentStation = 0;

   public:
    explicit RCAControl(std::string_view location) {
        _implementor = std::make_shared<RCA>(location);
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