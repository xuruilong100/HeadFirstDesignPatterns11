#include <vector>
#include "Client.hpp"

using namespace HeadFirstDesignPatterns::ChainOfResponsibility::
    GumballEMailHandler;

namespace {
const std::vector<std::string> email = {
    "You guys really razz my berries, your gumball machines are totally hip",
    "Cruisin for a bruisin? My kids lost their money trying to win gumballs!",
    "You guys make me frosted, you've got four year olds gambling now!",
    "Mighty Gumball machines are radioactive, keep up the good work!",
    "Mighty Gumball machines are a blast, I can't wait to see whats cooking "
    "next",
    "You guys got it made in the shade, these gumball machines are a kick",
    "Mighty Gumball machines are no where daddy-o",
    "Don't have a cow, but your gumball machines really rattle my cage",
    "What's your tale nightingale? slot machine arms on soda machines?!",
    "Wanna make some real bread?! build gumball machines in your home",
    "Grody? got cooties? call Freeman & Freeman, and you'll be in fat city",
    "What's buzzin cuzzin? Make some reals scratch delivering pizzas",
    "You guys are boss! I flip when I see those gumballs drop",
    "Mighty Gumball Inc. is in orbit, we love you guys!",
    "Your gumball machines really make the scene",
    "Cast an eyeball on this beauty",
    "We want gumball machines in all our stores!, sincerly Starbuzz"};
}

int main() {
    auto client = std::make_unique<Client>();

    for (const auto& e : email) {
        client->handleRequest(e);
    }

    client->print();

    return EXIT_SUCCESS;
}

// Output:
/*
Spam mail, send to shredder: count=3
 - wanna make some real bread?! build gumball machines in your home
 - what's buzzin cuzzin? make some reals scratch delivering pizzas
 - cast an eyeball on this beauty

Fan mail, send to CEO: count=6
 - you guys really razz my berries, your gumball machines are totally hip
 - mighty gumball machines are radioactive, keep up the good work!
 - mighty gumball machines are a blast, i can't wait to see whats cooking next
 - you guys got it made in the shade, these gumball machines are a kick
 - you guys are boss! i flip when i see those gumballs drop
 - mighty gumball inc. is in orbit, we love you guys!

Hate mail, send to Legal: count=5
 - cruisin for a bruisin? my kids lost their money trying to win gumballs!
 - you guys make me frosted, you've got four year olds gambling now!
 - mighty gumball machines are no where daddy-o
 - don't have a cow, but your gumball machines really rattle my cage
 - what's your tale nightingale? slot machine arms on soda machines?!

Request mail, send to Business Development: count=1
 - we want gumball machines in all our stores!, sincerly starbuzz

Unclassified, send to AI team: count=2
 - grody? got cooties? call freeman & freeman, and you'll be in fat city
 - your gumball machines really make the scene
*/