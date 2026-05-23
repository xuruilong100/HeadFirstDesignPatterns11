#pragma once

#include <iostream>
#include <memory>
#include "DisplayElement.hpp"
#include "Observer.hpp"
#include "WeatherData.hpp"

namespace HeadFirstDesignPatterns::Observer {
class StatisticsDisplay : private Observer, public DisplayElement {
   private:
    std::shared_ptr<WeatherData> _weatherData;
    float _maxTemp{0.0};
    float _minTemp{200.0F};
    float _tempSum{0.0};
    int _numReadings{0};

   public:
    explicit StatisticsDisplay(std::shared_ptr<WeatherData> weatherData)
        : _weatherData(std::move(weatherData)) {
        _weatherData->registerObserver(this);
    }
    StatisticsDisplay(const StatisticsDisplay&) = delete;
    StatisticsDisplay& operator=(const StatisticsDisplay&) = delete;
    StatisticsDisplay(StatisticsDisplay&&) = delete;
    StatisticsDisplay& operator=(StatisticsDisplay&&) = delete;

    ~StatisticsDisplay() override { _weatherData->removeObserver(this); }

    void update(float temp, float humidity, float pressure) override {
        _tempSum += temp;
        _numReadings++;

        if (temp > _maxTemp) {
            _maxTemp = temp;
        }

        if (temp < _minTemp) {
            _minTemp = temp;
        }

        display();
    }

    void display() const override {
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(3);
        std::cout << "Avg/Max/Min temperature = " << (_tempSum / _numReadings);
        std::cout << "/" << _maxTemp << "/" << _minTemp << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Observer