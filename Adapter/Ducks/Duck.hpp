#pragma once

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class Duck {
   public:
    virtual ~Duck() = default;

    virtual void fly() const = 0;
    virtual void quack() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks