#pragma once

#include <iostream>
#include <string>
#include "Fowl.hpp"
#include "Turkey.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class TurkeyAdapter : public Fowl {
   private:
    std::shared_ptr<Turkey> _turkey;

   public:
    explicit TurkeyAdapter(std::shared_ptr<Turkey> turkey)
        : _turkey(std::move(turkey)) {}
    TurkeyAdapter(const TurkeyAdapter&) = delete;
    void operator=(const TurkeyAdapter&) = delete;

    void quack() const override { _turkey->gobble(); }

    void swim() const override { _turkey->walk(); }

    std::string toString() const override { return _turkey->toString(); }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight