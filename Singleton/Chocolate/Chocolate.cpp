#include "ChocolateBoiler.hpp"

using namespace HeadFirstDesignPatterns::Factory::Singleton;

int main() {
    auto* boiler = ChocolateBoiler::getInstance();
    boiler->fill();
    boiler->boil();
    boiler->drain();

    // will return the existing instance
    auto* boiler2 = ChocolateBoiler::getInstance();

    if (boiler == boiler2)
        std::cout << "Got same boiler" << std::endl;
    else
        std::cout << "Oh oh! got a different boiler" << std::endl;

    return 0;
}

// Output:
/*
Creating unique instance of Chocolate Boiler
Returning instance of Chocolate Boiler
Creating unique instance of Chocolate Boiler
Returning instance of Chocolate Boiler
Got same boiler
*/