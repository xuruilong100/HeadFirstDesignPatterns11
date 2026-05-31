#pragma once

#include <iostream>
#include "GumballMachine.hpp"
#include "State.hpp"

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
class WinnerState : public State {
   private:
    GumballMachine* _gumballMachine;

   public:
    explicit WinnerState(GumballMachine* gumballMachine)
        : _gumballMachine(gumballMachine) {}
    WinnerState(const WinnerState&) = delete;
    WinnerState& operator=(const WinnerState&) = delete;
    WinnerState(WinnerState&&) = delete;
    WinnerState& operator=(WinnerState&&) = delete;

    void insertQuarter() const override {
        std::cout << "Please wait, we're already giving you a Gumball"
                  << std::endl;
    }

    void ejectQuarter() const override {
        std::cout << "Please wait, we're already giving you a Gumball"
                  << std::endl;
    }

    void turnCrank() const override {
        std::cout << "Turning again doesn't get you another gumball!"
                  << std::endl;
    }

    void dispense() override {
        std::cout << "YOU'RE A WINNER! You get two gumballs for your quarter"
                  << std::endl;
        _gumballMachine->releaseBall();
        if (_gumballMachine->getCount() == 0) {
            _gumballMachine->setState(_gumballMachine->getSoldOutState());
        } else {
            _gumballMachine->releaseBall();
            if (_gumballMachine->getCount() > 0) {
                _gumballMachine->setState(_gumballMachine->getNoQuarterState());
            } else {
                std::cout << "Oops, out of gumballs!" << std::endl;
                _gumballMachine->setState(_gumballMachine->getSoldOutState());
            }
        }
    }

    std::string toString() const override {
        return "despensing two gumballs for your quarter, because YOU'RE A "
               "WINNER!";
    }
};
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner