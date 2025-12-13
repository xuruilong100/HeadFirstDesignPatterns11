#pragma once

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class FlyBehavior {
   public:
    virtual ~FlyBehavior() = default;

    virtual void fly() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator