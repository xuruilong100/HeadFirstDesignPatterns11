#pragma once

#include <iostream>
#include <map>
#include <memory>
#include "Bird.hpp"
#include "Fowl.hpp"
#include "MallardDuck.hpp"
#include "ModelDuck.hpp"
#include "RedHeadDuck.hpp"
#include "RubberDuck.hpp"
#include "TurkeyAdapter.hpp"
#include "WildTurkey.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
// Flyweight Factory

// As also mentioned by GoF [pp 205] we could omit the operation getBird() and
// let clients instantiate unshared objects directly; however, if we decided to
// make these objects sharable later, we'll have to change client code that
// creates them.

class FowlFactory {
   private:
    std::map<Fowl::type, std::shared_ptr<Fowl>> map;

   public:
    FowlFactory() = default;
    FowlFactory(const FowlFactory&) = delete;
    void operator=(const FowlFactory&) = delete;

    std::shared_ptr<Fowl> getFowl(Fowl::type type) {
        std::shared_ptr<Fowl> value;

        if (auto iterator = map.find(type); iterator != map.end()) {
            value = iterator->second;
        } else {
            switch (type) {
                using enum Fowl::type;
                case mallard: {
                    value = std::make_shared<MallardDuck>();
                } break;
                case redhead: {
                    value = std::make_shared<RedheadDuck>();
                } break;
                case rubber: {
                    value = std::make_shared<RubberDuck>();
                } break;
                case model: {
                    value = std::make_shared<ModelDuck>();
                } break;
                case turkey: {
                    value = std::make_shared<TurkeyAdapter>(
                        std::make_shared<WildTurkey>());
                } break;
                default: {
                    value = std::make_shared<ModelDuck>();
                } break;
            }
            map[type] = value;
        }

        return value;
    }

    std::shared_ptr<Bird> getBird(Fowl::type type, int number, double weight) {
        return std::make_shared<Bird>(getFowl(type), number, weight);
    }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight