#pragma once

#include <iostream>
#include <memory>
#include "DisplayElement.hpp"
#include "Observer.hpp"
#include "Subject.hpp"

namespace HeadFirstDesignPatterns::Observer {
class CurrentConditionsDisplay : private Observer, public DisplayElement {
   private:
    std::shared_ptr<Subject> _weatherData;
    float _temperature{0.0};
    float _humidity{0.0};

   public:
    explicit CurrentConditionsDisplay(std::shared_ptr<Subject> weatherData)
        : _weatherData(std::move(weatherData)) {
        _weatherData->registerObserver(this);
    }

    CurrentConditionsDisplay(const CurrentConditionsDisplay&) = delete;
    CurrentConditionsDisplay& operator=(const CurrentConditionsDisplay&) =
        delete;
    CurrentConditionsDisplay(CurrentConditionsDisplay&&) = delete;
    CurrentConditionsDisplay& operator=(CurrentConditionsDisplay&&) = delete;

    ~CurrentConditionsDisplay() override { _weatherData->removeObserver(this); }

    void update(float temperature, float humidity, float pressure) override {
        _temperature = temperature;
        _humidity = humidity;
        display();
    }

    void display() const override {
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(3);
        std::cout << "Current conditions: " << _temperature;
        std::cout << " F degrees and " << _humidity;
        std::cout << "% humidity" << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Observer