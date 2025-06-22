#pragma once

#include <cstdlib>
#include <memory>
#include "Duck.hpp"
#include "Turkey.hpp"

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class DuckAdapter : public Turkey {
   private:
    std::shared_ptr<Duck> _duck;
    int _random;

   public:
    explicit DuckAdapter(std::shared_ptr<Duck> duck) : _duck(std::move(duck)) {
        _random = rand() % 5;
        ++_random;
    }
    DuckAdapter(const DuckAdapter&) = delete;
    DuckAdapter& operator=(const DuckAdapter&) = delete;
    DuckAdapter(DuckAdapter&&) = default;
    DuckAdapter& operator=(DuckAdapter&&) = default;

    void fly() const override {
        for (int i = 0; i < _random; i++) {
            _duck->fly();
        }
    }

    void gobble() const override { _duck->quack(); }
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks