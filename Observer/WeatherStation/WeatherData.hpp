#pragma once

#include <list>
#include <memory>
#include "Observer.hpp"
#include "Subject.hpp"

namespace HeadFirstDesignPatterns::Observer {
class WeatherData : public Subject {
   private:
    std::list<Observer*> _observers;
    float _temperature{0.0};
    float _humidity{0.0};
    float _pressure{0.0};

   public:
    WeatherData() = default;
    WeatherData(const WeatherData&) = delete;
    WeatherData& operator=(const WeatherData&) = delete;
    WeatherData(WeatherData&&) = delete;
    WeatherData& operator=(WeatherData&&) = delete;

    void registerObserver(Observer* o) override { _observers.push_back(o); }

    void removeObserver(Observer* o) override { _observers.remove(o); }

    void notifyObservers() const override {
        for (const auto& observer : _observers) {
            observer->update(_temperature, _humidity, _pressure);
        }
    }

    void measurementsChanged() const { notifyObservers(); }

    void setMeasurements(float temperature, float humidity, float pressure) {
        _temperature = temperature;
        _humidity = humidity;
        _pressure = pressure;
        measurementsChanged();
    }

    // other WeatherData methods here

    float getTemperature() const { return _temperature; }

    float getHumidity() const { return _humidity; }

    float getPressure() const { return _pressure; }
};
}  // namespace HeadFirstDesignPatterns::Observer