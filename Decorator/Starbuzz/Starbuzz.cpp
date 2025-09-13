#include <iostream>
#include "Beverage.hpp"
#include "DarkRoast.hpp"
#include "Espresso.hpp"
#include "HouseBlend.hpp"
#include "Mocha.hpp"
#include "Soy.hpp"
#include "Whip.hpp"

using namespace HeadFirstDesignPatterns::Decorator;

int main() {
    std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>();

    std::cout.setf(std::ios::showpoint);
    std::cout.precision(3);
    std::cout << beverage->getDescription() << " $" << beverage->cost()
              << std::endl;

    std::shared_ptr<Beverage> beverage2 = std::make_shared<DarkRoast>();
    beverage2 = std::make_shared<Mocha>(beverage2);
    beverage2 = std::make_shared<Mocha>(beverage2);
    beverage2 = std::make_shared<Whip>(beverage2);
    std::cout << beverage2->getDescription() << " $" << beverage2->cost()
              << std::endl;

    std::shared_ptr<Beverage> beverage3 = std::make_shared<HouseBlend>();
    beverage3 = std::make_shared<Soy>(beverage3);
    beverage3 = std::make_shared<Mocha>(beverage3);
    beverage3 = std::make_shared<Whip>(beverage3);
    std::cout << beverage3->getDescription() << " $" << beverage3->cost()
              << std::endl;

    return EXIT_SUCCESS;
}

// Output:
/*
Espresso $1.99
Dark Roast Coffee, Mocha, Mocha, Whip $1.49
House Blend Coffee, Soy, Mocha, Whip $1.34
*/