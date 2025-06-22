#pragma once

namespace HeadFirstDesignPatterns::Adapter::Ducks {
class Turkey {
   public:
    virtual ~Turkey() = default;

    virtual void gobble() const = 0;
    virtual void fly() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Adapter::Ducks