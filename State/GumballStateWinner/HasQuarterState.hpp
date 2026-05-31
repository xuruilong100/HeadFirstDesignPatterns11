#pragma once

#include <cstdlib>
#include <iostream>
#include "GumballMachine.hpp"
#include "State.hpp"

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
class HasQuarterState : public State {
   private:
    GumballMachine* _gumballMachine;

   public:
    explicit HasQuarterState(GumballMachine* gumballMachine)
        : _gumballMachine(gumballMachine) {
        srand(42);
    }
    HasQuarterState(const HasQuarterState&) = delete;
    HasQuarterState& operator=(const HasQuarterState&) = delete;
    HasQuarterState(HasQuarterState&&) = delete;
    HasQuarterState& operator=(HasQuarterState&&) = delete;

    void insertQuarter() const override {
        std::cout << "You can't insert another quarter" << std::endl;
    }

    void ejectQuarter() const override {
        std::cout << "Quarter returned" << std::endl;
        _gumballMachine->setState(_gumballMachine->getNoQuarterState());
    }

    void turnCrank() const override {
        std::cout << "You turned..." << std::endl;
        int winner = rand() % 5;
        if ((winner == 0) && (_gumballMachine->getCount() > 0)) {
            _gumballMachine->setState(_gumballMachine->getWinnerState());
        } else {
            _gumballMachine->setState(_gumballMachine->getSoldState());
        }
    }

    void dispense() override {
        std::cout << "No gumball dispensed" << std::endl;
    }

    std::string toString() const override {
        return "waiting for turn of crank";
    }
};
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner