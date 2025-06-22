#include "Duck.hpp"
#include "DuckAdapter.hpp"
#include "MallardDuck.hpp"
#include "TurkeyAdapter.hpp"
#include "WildTurkey.hpp"

using namespace HeadFirstDesignPatterns::Adapter::Ducks;

void testDuck(const std::shared_ptr<Duck>& duck) {
    duck->quack();
    duck->fly();
}

int main() {
    auto duck = std::make_shared<MallardDuck>();
    auto duckAdapter = std::make_shared<DuckAdapter>(duck);

    for (int i = 0; i < 10; i++) {
        std::cout << "The DuckAdapter says..." << std::endl;
        duckAdapter->gobble();
        duckAdapter->fly();
    }

    auto turkey = std::make_shared<WildTurkey>();
    auto turkeyAdapter = std::make_shared<TurkeyAdapter>(turkey);

    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << std::endl << "The Duck says..." << std::endl;
    testDuck(duck);

    std::cout << std::endl << "The TurkeyAdapter says..." << std::endl;
    testDuck(turkeyAdapter);

    return 0;
}