#include "PizzaStore.hpp"
#include "SimplePizzaFactory.hpp"

using namespace HeadFirstDesignPatterns::Factory::Simple;

int main() {
    auto factory = std::make_shared<SimplePizzaFactory>();
    auto store = std::make_shared<PizzaStore>(factory);

    auto pizza = store->orderPizza("cheese");
    std::cout << "We ordered a " << pizza->getName() << std::endl;

    pizza = store->orderPizza("veggie");
    std::cout << "We ordered a " << pizza->getName() << std::endl;

    return EXIT_SUCCESS;
}

// Output:
/*
Preparing Cheese Pizza
Baking Cheese Pizza
Cutting Cheese Pizza
Boxing Cheese Pizza
We ordered a Cheese Pizza
Preparing Veggie Pizza
Baking Veggie Pizza
Cutting Veggie Pizza
Boxing Veggie Pizza
We ordered a Veggie Pizza
*/