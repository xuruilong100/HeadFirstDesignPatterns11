#pragma once

#include <iostream>
#include "GumballMachine.hpp"
#include "State.hpp"

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
class SoldOutState : public State {
   private:
    GumballMachine* _gumballMachine;

   public:
    explicit SoldOutState(GumballMachine* gumballMachine)
        : _gumballMachine(gumballMachine) {}
    SoldOutState(const SoldOutState&) = delete;
    SoldOutState& operator=(const SoldOutState&) = delete;
    SoldOutState(SoldOutState&&) = delete;
    SoldOutState& operator=(SoldOutState&&) = delete;

    void insertQuarter() const override {
        std::cout << "You can't insert a quarter, the machine is sold out"
                  << std::endl;
    }

    void ejectQuarter() const override {
        std::cout << "You can't eject, you haven't inserted a quarter yet"
                  << std::endl;
    }

    void turnCrank() const override {
        std::cout << "You turned, but there are no gumballs" << std::endl;
    }

    void dispense() override {
        std::cout << "No gumball dispensed" << std::endl;
    }

    std::string toString() const override { return "sold out"; }
};
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner