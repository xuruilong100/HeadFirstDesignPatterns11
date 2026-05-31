#pragma once

#include <iostream>
#include "GumballMachine.hpp"
#include "State.hpp"

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
class SoldState : public State {
   private:
    GumballMachine* _gumballMachine;

   public:
    explicit SoldState(GumballMachine* gumballMachine)
        : _gumballMachine(gumballMachine) {}
    SoldState(const SoldState&) = delete;
    SoldState& operator=(const SoldState&) = delete;
    SoldState(SoldState&&) = delete;
    SoldState& operator=(SoldState&&) = delete;

    void insertQuarter() const override {
        std::cout << "Please wait, we're already giving you a gumball"
                  << std::endl;
    }

    void ejectQuarter() const override {
        std::cout << "Sorry, you already turned the crank" << std::endl;
    }

    void turnCrank() const override {
        std::cout << "Turning twice doesn't get you another gumball!"
                  << std::endl;
    }

    void dispense() override {
        _gumballMachine->releaseBall();
        if (_gumballMachine->getCount() > 0) {
            _gumballMachine->setState(_gumballMachine->getNoQuarterState());
        } else {
            std::cout << "Oops, out of gumballs!" << std::endl;
            _gumballMachine->setState(_gumballMachine->getSoldOutState());
        }
    }

    std::string toString() const override { return "dispensing a gumball"; }
};
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner