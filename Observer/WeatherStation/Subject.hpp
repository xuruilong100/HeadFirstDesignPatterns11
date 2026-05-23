#pragma once

#include "Observer.hpp"

namespace HeadFirstDesignPatterns::Observer {
class Subject {
   protected:
    virtual ~Subject() = default;

   public:
    virtual void registerObserver(Observer* o) = 0;

    virtual void removeObserver(Observer* o) = 0;

    virtual void notifyObservers() const = 0;
};
}  // namespace HeadFirstDesignPatterns::Observer