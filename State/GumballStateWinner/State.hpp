#pragma once

#include <string>

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
class State {
   public:
    State() = default;
    virtual ~State() = default;

    virtual void insertQuarter() const = 0;
    virtual void ejectQuarter() const = 0;
    virtual void turnCrank() const = 0;
    virtual void dispense() = 0;
    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner