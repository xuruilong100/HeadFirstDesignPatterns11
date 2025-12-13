#pragma once

#include <iostream>
#include <memory>
#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class Duck {
   private:
    std::shared_ptr<FlyBehavior> _flyBehavior;
    std::shared_ptr<QuackBehavior> _quackBehavior;

   protected:
    Duck(std::shared_ptr<FlyBehavior> flyBehavior,
         std::shared_ptr<QuackBehavior> quackBehavior)
        : _flyBehavior(std::move(flyBehavior)),
          _quackBehavior(std::move(quackBehavior)) {}

   public:
    Duck(const Duck&) = delete;
    void operator=(const Duck&) = delete;
    virtual ~Duck() = default;

    void setFlyBehavior(std::shared_ptr<FlyBehavior> fb) {
        _flyBehavior = std::move(fb);
    }

    void setQuackBehavior(std::shared_ptr<QuackBehavior> qb) {
        _quackBehavior = std::move(qb);
    }

    void fly() const { _flyBehavior->fly(); }

    void quack() const { _quackBehavior->quack(); }

    void swim() const {
        std::cout << "All ducks float, even decoys!" << std::endl;
    }

    virtual void display() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator