#include <vector>
#include "RCAControl.hpp"
#include "RemoteControl.hpp"
#include "SonyControl.hpp"

using namespace HeadFirstDesignPatterns::Bridge::Remotes;

int main() {
    std::vector<std::shared_ptr<RemoteControl>> remotes;

    auto sonyControl = std::make_shared<SonyControl>("XBR in living room");
    remotes.push_back(sonyControl);

    auto rcaControl = std::make_shared<RCAControl>("19 inch in kitchen");
    remotes.push_back(rcaControl);

    // turn on all tv's
    for (const auto& r : remotes) {
        r->on();
    }

    sonyControl->nextChannel();
    rcaControl->setStation(35);

    // turn off all tv's
    for (const auto& r : remotes) {
        r->off();
    }

    return 0;
}