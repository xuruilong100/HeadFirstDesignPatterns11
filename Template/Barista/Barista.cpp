#include "Coffee.hpp"
#include "CoffeeWithHook.hpp"
#include "Tea.hpp"
#include "TeaWithHook.hpp"

using namespace HeadFirstDesignPatterns::Template::Barista;

int main() {
    auto tea = std::make_shared<Tea>();
    auto coffee = std::make_shared<Coffee>();

    std::cout << std::endl << "Making tea..." << std::endl;
    tea->prepareRecipe();

    std::cout << std::endl << "Making coffee..." << std::endl;
    coffee->prepareRecipe();

    auto teaHook = std::make_shared<TeaWithHook>();
    auto coffeeHook = std::make_shared<CoffeeWithHook>();

    std::cout << std::endl << "Making tea..." << std::endl;
    teaHook->prepareRecipe();

    std::cout << std::endl << "Making coffee..." << std::endl;
    coffeeHook->prepareRecipe();

    return EXIT_SUCCESS;
}

// Output:
/*
Making tea...
Boiling water
Steeping the tea
Pouring into cup
Adding Lemon

Making coffee...
Boiling water
Dripping Coffee through filter
Pouring into cup
Adding Sugar and Milk

Making tea...
Boiling water
Steeping the tea
Pouring into cup
Would you like lemon with your tea (y/n)?
y
Adding Lemon

Making coffee...
Boiling water
Dripping Coffee through filter
Pouring into cup
Would you like milk and sugar with your coffee (y/n)?
y
Adding Sugar and Milk
*/