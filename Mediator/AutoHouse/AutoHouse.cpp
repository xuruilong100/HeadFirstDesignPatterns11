#include "AutoHouse.hpp"

using namespace HeadFirstDesignPatterns::Mediator::AutoHouse;

// The 'Mediator' pattern is discussed on page 622 in 'Head First Design
// Patterns'.
//
// As always, my intent is to implement the example as described in the book;
// however, there are some embellishments: WeatherStation and automation.
//
// The WeatherStation knows if it is raining and automation is accomplished by
// two variables: 'interval' and 'iterations' specifying the length of a virtual
// day and the number of days to simulate respectively. The default is a
// simulated (yet accelerated) 24 hour day that runs for a simulated week.
//
// You can override these values with command-line parameters.

int main() {
    unsigned long interval = 12;   // length of day (in seconds)
    unsigned long iterations = 7;  // number of days to simulate

    // TODO: Mediator could/should be implemented as a 'Singleton'
    auto mediator = std::make_shared<Mediator>(iterations);
    mediator->on(interval);

    return 0;
}

// Output:
/*
Auto-house is on
Calendar is on

Calendar -- It's Sunday
Calendar -- It's the weekend (no alarm)
Weather station -- It's nice weather (not raining)
Sprinkler is on
Sprinkler -- finished
Sprinkler is off

Calendar -- It's Monday
Calendar -- It's trash day, setting the alarm (early)
Alarm is on
Weather station -- It's nice weather (not raining)
Sprinkler is on
Alarm -- Buzzzzz!
Coffeepot is on
Sprinkler is off
Shower is on
Sprinkler -- finished
Sprinkler is off
Coffeepot -- finished
Coffeepot is off
Shower is off
Alarm is off

Calendar -- It's Tuesday
Calendar -- It's a work day, setting the alarm
Alarm is on
Weather station -- It's duck weather (raining)
Alarm -- Buzzzzz!
Coffeepot is on
Sprinkler is off
Shower is on
Coffeepot -- finished
Coffeepot is off
Shower is off
Alarm is off

Calendar -- It's Wednsday
Calendar -- It's a work day, setting the alarm
Alarm is on
Weather station -- It's duck weather (raining)
Alarm -- Buzzzzz!
Coffeepot is on
Sprinkler is off
Shower is on
Shower is off
Alarm is off
Coffeepot -- finished
Coffeepot is off

Calendar -- It's Thursday
Calendar -- It's a work day, setting the alarm
Alarm is on
Weather station -- It's nice weather (not raining)
Sprinkler is on
Alarm -- Buzzzzz!
Coffeepot is on
Sprinkler is off
Shower is on
Sprinkler -- finished
Sprinkler is off
Coffeepot -- finished
Coffeepot is off
Shower is off
Alarm is off

Calendar -- It's Friday
Calendar -- It's trash day, setting the alarm (early)
Alarm is on
Weather station -- It's duck weather (raining)
Alarm -- Buzzzzz!
Coffeepot is on
Sprinkler is off
Shower is on
Shower is off
Alarm is off
Coffeepot -- finished
Coffeepot is off

Calendar -- It's Saturday
Calendar -- It's the weekend (no alarm)
Weather station -- It's duck weather (raining)
Calendar is off
Coffeepot is off
Sprinkler is off
Shower is off
Weather station is off

Auto-house is off
*/