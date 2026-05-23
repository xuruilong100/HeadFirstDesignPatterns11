#pragma once

#include <iostream>
#include <memory>
#include <mutex>

namespace HeadFirstDesignPatterns::Factory::Singleton {
class ChocolateBoiler {
   private:
    bool _empty{true};
    bool _boiled{false};
    mutable std::mutex _mutex;

    ChocolateBoiler() = default;

   public:
    ChocolateBoiler(const ChocolateBoiler&) = delete;
    ChocolateBoiler& operator=(const ChocolateBoiler&) = delete;
    ChocolateBoiler(ChocolateBoiler&&) = delete;
    ChocolateBoiler& operator=(ChocolateBoiler&&) = delete;

    ~ChocolateBoiler() = default;

    static ChocolateBoiler* getInstance() {
        std::cout << "Creating unique instance of Chocolate Boiler"
                  << std::endl;
        static ChocolateBoiler uniqueInstance;
        std::cout << "Returning instance of Chocolate Boiler" << std::endl;
        return &uniqueInstance;
    }

    void fill() {
        std::lock_guard<std::mutex> lock(_mutex);
        if (_empty) {
            _empty = false;
            _boiled = false;
        }
    }

    void drain() {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!_empty && _boiled) {
            _empty = true;
        }
    }

    void boil() {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!_empty && !_boiled) {
            _boiled = true;
        }
    }

    bool isEmpty() const {
        std::lock_guard<std::mutex> lock(_mutex);
        return _empty;
    }

    bool isBoiled() const {
        std::lock_guard<std::mutex> lock(_mutex);
        return _boiled;
    }
};
}  // namespace HeadFirstDesignPatterns::Factory::Singleton