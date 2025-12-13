#pragma once

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class QuackBehavior {
   public:
    virtual ~QuackBehavior() = default;

    virtual void quack() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator