#pragma once

#include <iostream>
#include "GumballMachine.hpp"
#include "State.hpp"

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
class NoQuarterState : public State {
   private:
    GumballMachine* _gumballMachine;

   public:
    explicit NoQuarterState(GumballMachine* gumballMachine)
        : _gumballMachine(gumballMachine) {}
    NoQuarterState(const NoQuarterState&) = delete;
    NoQuarterState& operator=(const NoQuarterState&) = delete;
    NoQuarterState(NoQuarterState&&) = delete;
    NoQuarterState& operator=(NoQuarterState&&) = delete;

    void insertQuarter() const override {
        std::cout << "You inserted a quarter" << std::endl;
        _gumballMachine->setState(_gumballMachine->getHasQuarterState());
    }

    void ejectQuarter() const override {
        std::cout << "You haven't inserted a quarter" << std::endl;
    }

    void turnCrank() const override {
        std::cout << "You turned, but there's no quarter" << std::endl;
    }

    void dispense() override {
        std::cout << "You need to pay first" << std::endl;
    }

    std::string toString() const override { return "waiting for quarter"; }
};
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner