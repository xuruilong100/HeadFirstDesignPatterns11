#pragma once

#include <string>

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class Fowl {
   protected:
    Fowl() = default;

   public:
    enum class type { mallard, redhead, rubber, model, turkey, last };

    virtual ~Fowl() = default;

    virtual void quack() const = 0;

    virtual void swim() const = 0;

    virtual std::string toString() const = 0;
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight