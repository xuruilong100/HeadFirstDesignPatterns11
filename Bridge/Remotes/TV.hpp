#pragma once

namespace HeadFirstDesignPatterns::Bridge::Remotes {
class TV {
   public:
    TV() = default;
    virtual ~TV() = default;

    virtual void on() = 0;
    virtual void off() = 0;
    virtual void tuneChannel(unsigned int channel) = 0;
};
}  // namespace HeadFirstDesignPatterns::Bridge::Remotes