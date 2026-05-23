#pragma once

namespace HeadFirstDesignPatterns::Observer {
class Observer {
   public:
    virtual ~Observer() = default;

    virtual void update(float temp, float humidity, float pressure) = 0;
};
}  // namespace HeadFirstDesignPatterns::Observer