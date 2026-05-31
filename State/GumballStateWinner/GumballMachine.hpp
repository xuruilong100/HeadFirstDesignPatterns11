#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "State.hpp"

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
class GumballMachine {
   private:
    std::shared_ptr<State> _soldOutState;
    std::shared_ptr<State> _noQuarterState;
    std::shared_ptr<State> _hasQuarterState;
    std::shared_ptr<State> _soldState;
    std::shared_ptr<State> _winnerState;
    std::shared_ptr<State> _state;
    int _count;

   public:
    explicit GumballMachine(int numberGumballs);
    GumballMachine(const GumballMachine&) = delete;
    GumballMachine& operator=(const GumballMachine&) = delete;
    GumballMachine(GumballMachine&&) = delete;
    GumballMachine& operator=(GumballMachine&&) = delete;
    ~GumballMachine() = default;

    void insertQuarter() const { _state->insertQuarter(); }
    void ejectQuarter() const { _state->ejectQuarter(); }

    void turnCrank() const {
        _state->turnCrank();
        _state->dispense();
    }

    void setState(std::shared_ptr<State> state) { _state = std::move(state); }

    void releaseBall() {
        std::cout << "A gumball comes rolling out the slot..." << std::endl;
        if (_count != 0) {
            _count--;
        }
    }

    int getCount() const { return _count; }

    void refill(int count) {
        _count = count;
        _state = _noQuarterState;
    }

    const auto& getState() const { return _state; }
    const auto& getSoldOutState() const { return _soldOutState; }
    const auto& getNoQuarterState() const { return _noQuarterState; }
    const auto& getHasQuarterState() const { return _hasQuarterState; }
    const auto& getSoldState() const { return _soldState; }
    const auto& getWinnerState() const { return _winnerState; }

    std::string toString() const {
        std::stringstream value;
        value << std::endl << "Mighty Gumball, Inc.";
        value << std::endl << "C++-enabled Standing Gumball Model #2004";
        value << std::endl << "Inventory: " << _count << " gumball";
        if (_count > 1) {
            value << "s";
        }
        value << std::endl;
        value << "Machine is " << _state->toString() << std::endl;
        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner