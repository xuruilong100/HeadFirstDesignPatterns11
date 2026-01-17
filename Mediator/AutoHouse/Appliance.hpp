#pragma once

#include <memory>

namespace HeadFirstDesignPatterns::Mediator::AutoHouse {
class Mediator;

class Appliance {
   protected:
    Mediator* _mediator;

   public:
    explicit Appliance(Mediator* mediator) : _mediator(mediator) {}
    virtual ~Appliance() = default;

    virtual void off() = 0;
    virtual void on(unsigned long value) = 0;
    virtual void onEvent(unsigned long value) = 0;
};
}  // namespace HeadFirstDesignPatterns::Mediator::AutoHouse