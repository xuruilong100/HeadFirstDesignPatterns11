#pragma once

#include <iostream>
#include <memory>
#include "DisplayElement.hpp"
#include "Observer.hpp"
#include "WeatherData.hpp"

namespace HeadFirstDesignPatterns::Observer {
class ForecastDisplay : private Observer, public DisplayElement {
   private:
    std::shared_ptr<WeatherData> _weatherData;
    float _currentPressure{29.92f};
    float _lastPressure{0.0};

   public:
    explicit ForecastDisplay(std::shared_ptr<WeatherData> weatherData)
        : _weatherData(std::move(weatherData)) {
        _weatherData->registerObserver(this);
    }
    ForecastDisplay(const ForecastDisplay&) = delete;
    ForecastDisplay& operator=(const ForecastDisplay&) = delete;
    ForecastDisplay(ForecastDisplay&&) = delete;
    ForecastDisplay& operator=(ForecastDisplay&&) = delete;

    ~ForecastDisplay() override { _weatherData->removeObserver(this); }

    void update(float temp, float humidity, float pressure) override {
        _lastPressure = _currentPressure;
        _currentPressure = pressure;
        display();
    }

    void display() const override {
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(3);
        std::cout << "Forecast: ";
        if (_currentPressure > _lastPressure) {
            std::cout << "Improving weather on the way!";
        } else if (_currentPressure == _lastPressure) {
            std::cout << "More of the same";
        } else if (_currentPressure < _lastPressure) {
            std::cout << "Watch out for cooler, rainy weather";
        }
        std::cout << std::endl;
    }
};
}  // namespace HeadFirstDesignPatterns::Observer