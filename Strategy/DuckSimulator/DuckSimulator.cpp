#include "DecoyDuck.hpp"
#include "FlyRocketPowered.hpp"
#include "MallardDuck.hpp"
#include "ModelDuck.hpp"
#include "RubberDuck.hpp"

using namespace HeadFirstDesignPatterns::Strategy;

int main() {
    auto mallard = std::make_shared<MallardDuck>();
    auto rubberDuckie = std::make_shared<RubberDuck>();
    auto decoy = std::make_shared<DecoyDuck>();
    auto model = std::make_shared<ModelDuck>();

    mallard->performQuack();
    mallard->performFly();

    rubberDuckie->performQuack();
    rubberDuckie->performFly();

    decoy->performQuack();
    decoy->performFly();

    model->performQuack();
    model->performFly();
    model->setFlyBehavior(std::make_shared<FlyRocketPowered>());
    model->performFly();

    return EXIT_SUCCESS;
}

// Output:
/*
Quack
I'm flying!!
Squeak
I can't fly
<< Silence >>
I can't fly
Qwak
I can't fly
I'm flying with a rocket
*/