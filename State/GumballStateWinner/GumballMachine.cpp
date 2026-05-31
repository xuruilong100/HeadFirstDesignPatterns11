#include "GumballMachine.hpp"
#include "HasQuarterState.hpp"
#include "NoQuarterState.hpp"
#include "SoldOutState.hpp"
#include "SoldState.hpp"
#include "WinnerState.hpp"

namespace HeadFirstDesignPatterns::State::GumballStateWinner {
//
// put here to resolve forward reference paradox where GumballMachine
// references State(s) and State references GumballMachine. Note, a
// simple forward 'class' reference is not sufficient to resolve the
// circular (chicken&egg) paradox. Morever, since the intent is to
// preserve as much of the original examples, this minor deviation is
// acceptable.
//
GumballMachine::GumballMachine(int numberGumballs) : _count(numberGumballs) {
    _soldOutState = std::make_shared<SoldOutState>(this);
    _noQuarterState = std::make_shared<NoQuarterState>(this);
    _hasQuarterState = std::make_shared<HasQuarterState>(this);
    _soldState = std::make_shared<SoldState>(this);
    _winnerState = std::make_shared<WinnerState>(this);
    _state = _soldOutState;

    if (_count > 0) {
        _state = _noQuarterState;
    }
}
}  // namespace HeadFirstDesignPatterns::State::GumballStateWinner