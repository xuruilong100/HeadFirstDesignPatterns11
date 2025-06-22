#pragma once

#include <memory>
#include "Duck.hpp"
#include "Turkey.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class TurkeyAdapter : public Duck {
   private:
    std::shared_ptr<Turkey> _turkey;

   public:
    explicit TurkeyAdapter(std::shared_ptr<Turkey> turkey)
        : _turkey(std::move(turkey)) {}
    TurkeyAdapter(const TurkeyAdapter&) = delete;
    TurkeyAdapter& operator=(const TurkeyAdapter&) = delete;
    TurkeyAdapter(TurkeyAdapter&&) = default;
    TurkeyAdapter& operator=(TurkeyAdapter&&) = default;

    void fly() const override {
        for (int i = 0; i < 5; i++) {
            _turkey->fly();
        }
    }

    void quack() const override { _turkey->gobble(); }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks