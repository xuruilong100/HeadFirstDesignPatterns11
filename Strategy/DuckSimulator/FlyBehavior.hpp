#pragma once

namespace HeadFirstDesignPatterns::Strategy {
class FlyBehavior {
   public:
    FlyBehavior() = default;
    virtual ~FlyBehavior() = default;

    virtual void fly() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Strategy