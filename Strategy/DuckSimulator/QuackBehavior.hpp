#pragma once

namespace HeadFirstDesignPatterns::Strategy {
class QuackBehavior {
   public:
    QuackBehavior() = default;
    virtual ~QuackBehavior() = default;

    virtual void quack() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Strategy