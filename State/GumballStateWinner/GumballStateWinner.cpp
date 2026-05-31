#include "GumballMachine.hpp"

using namespace HeadFirstDesignPatterns::State::GumballStateWinner;

int main() {
    auto gumballMachine = std::make_shared<GumballMachine>(10);
    std::cout << gumballMachine->toString() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->toString() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->toString() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->toString() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->toString() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->toString() << std::endl;

    return 0;
}

// Output:
/*
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2004
Inventory: 10 gumballs
Machine is waiting for quarter

You inserted a quarter
You turned...
YOU'RE A WINNER! You get two gumballs for your quarter
A gumball comes rolling out the slot...
A gumball comes rolling out the slot...
You inserted a quarter
You turned...
YOU'RE A WINNER! You get two gumballs for your quarter
A gumball comes rolling out the slot...
A gumball comes rolling out the slot...

Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2004
Inventory: 6 gumballs
Machine is waiting for quarter

You inserted a quarter
You turned...
A gumball comes rolling out the slot...
You inserted a quarter
You turned...
A gumball comes rolling out the slot...

Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2004
Inventory: 4 gumballs
Machine is waiting for quarter

You inserted a quarter
You turned...
A gumball comes rolling out the slot...
You inserted a quarter
You turned...
A gumball comes rolling out the slot...

Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2004
Inventory: 2 gumballs
Machine is waiting for quarter

You inserted a quarter
You turned...
A gumball comes rolling out the slot...
You inserted a quarter
You turned...
A gumball comes rolling out the slot...
Oops, out of gumballs!

Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2004
Inventory: 0 gumball
Machine is sold out

You can't insert a quarter, the machine is sold out
You turned, but there are no gumballs
No gumball dispensed
You can't insert a quarter, the machine is sold out
You turned, but there are no gumballs
No gumball dispensed

Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2004
Inventory: 0 gumball
Machine is sold out
*/