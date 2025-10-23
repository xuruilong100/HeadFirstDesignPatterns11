#include <process.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Bird.hpp"
#include "FowlFactory.hpp"

using namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight;

static const int MAX_BIRDS = 100;
static const double MIN_WIEGHT = 0.1;

int main() {
    FowlFactory fowlFactory;

    // Create a flock of mixed birds with random weights and tag them with a
    // number

    std::vector<std::shared_ptr<Bird>> flock;
    flock.resize(MAX_BIRDS);

    srand(42);
    for (int i = 0; i < MAX_BIRDS; i++) {
        auto type = static_cast<Fowl::type>(rand() %
                                            static_cast<int>(Fowl::type::last));
        double weight = (rand() % 100) * MIN_WIEGHT;
        if (weight < MIN_WIEGHT) {
            weight = MIN_WIEGHT;
        }
        flock[i] = fowlFactory.getBird(type, i, weight);
    }

    //	Sort flock by ascending weight and display a journal

    std::sort(flock.begin(), flock.end(), [](const auto& lhs, const auto& rhs) {
        return lhs->getWeight() < rhs->getWeight();
    });

    for (const auto& f : flock) {
        std::cout << f->toString();
        std::cout << ", says \"";
        f->quack();
        std::cout << "\" and ";
        f->swim();
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}