#pragma once

#include <memory>
#include <mutex>
#include <string_view>

namespace HeadFirstDesignPatterns::Mediator::AutoHouse {
// Ommitting the abstract Mediator class. There's no need to define an abstract
// Mediator class when colleagues work with only one mediator. The abstract
// coupling that the Mediator class provides lets collegues work with different
// Mediator subclasses, and vice versa. [Gof] p.278 "Implementation" item #1.

class Alarm;
class Calendar;
class CoffeePot;
class Sprinkler;
class Shower;
class WeatherStation;
class Appliance;

class Mediator /*: public std::enable_shared_from_this<Mediator>*/ {
   private:
    std::shared_ptr<Alarm> _alarm;
    std::shared_ptr<Calendar> _calendar;
    std::shared_ptr<CoffeePot> _coffeePot;
    std::shared_ptr<Sprinkler> _sprinkler;
    std::shared_ptr<Shower> _shower;
    std::shared_ptr<WeatherStation> _weatherStation;

    unsigned long _interval;
    unsigned long _iterations;
    mutable std::mutex _mutex;

   public:
    explicit Mediator(unsigned long iterations);
    ~Mediator();

    void on(unsigned long interval);

    void onEvent(const Appliance* appliance, unsigned long value) const;

    void off();

    void output(std::string_view value,
                bool before = false,
                bool after = true) const;
};
}  // namespace HeadFirstDesignPatterns::Mediator::AutoHouse