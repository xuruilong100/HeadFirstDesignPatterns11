#include "WeatherStation.hpp"

using namespace HeadFirstDesignPatterns::Observer;

int main() {
    auto weatherData = std::make_shared<WeatherData>();

    CurrentConditionsDisplay currentDisplay(weatherData);
    StatisticsDisplay statisticsDisplay(weatherData);
    ForecastDisplay forecastDisplay(weatherData);
    HeatIndexDisplay heatIndexDisplay(weatherData);

    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.2f);
    weatherData->setMeasurements(78, 90, 29.2f);

    return 0;
}

// Output:
/*
Current conditions: 80.0 F degrees and 65.0% humidity
Avg/Max/Min temperature = 80.0/80.0/80.0
Forecast: Improving weather on the way!
Heat index is 82.95535
Current conditions: 82.0 F degrees and 70.0% humidity
Avg/Max/Min temperature = 81.0/82.0/80.0
Forecast: Watch out for cooler, rainy weather
Heat index is 86.90124
Current conditions: 78.0 F degrees and 90.0% humidity
Avg/Max/Min temperature = 80.0/82.0/78.0
Forecast: More of the same
Heat index is 83.64967
*/