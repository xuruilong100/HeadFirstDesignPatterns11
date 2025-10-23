#pragma once

#include <memory>
#include <sstream>
#include <string>
#include "Fowl.hpp"

namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight {
class Bird : public Fowl {
   private:
    std::shared_ptr<Fowl> _fowl;
    int _number;
    double _weight;

   public:
    Bird(std::shared_ptr<Fowl> fowl, int number, double weight)
        : _fowl(std::move(fowl)), _number(number), _weight(weight) {}
    Bird(const Bird&) = delete;
    void operator=(const Bird&) = delete;

    void quack() const override { _fowl->quack(); }

    void swim() const override { _fowl->swim(); }

    double getWeight() const { return _weight; }

    double getNumber() const { return _number; }

    std::string toString() const override {
        std::stringstream value;
        value << "Bird #" << _number + 1 << ", ";
        value << "weighs " << _weight << " pounds, ";
        value << "is a " << _fowl->toString();
        return value.str();
    }
};
}  // namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight