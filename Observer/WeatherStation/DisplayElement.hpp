#pragma once

namespace HeadFirstDesignPatterns::Observer {
class DisplayElement {
   public:
    virtual ~DisplayElement() = default;

    virtual void display() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Observer