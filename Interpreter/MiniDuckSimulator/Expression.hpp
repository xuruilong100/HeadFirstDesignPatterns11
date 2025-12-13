#pragma once

#include <memory>

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class Visitor;

class Expression {
   public:
    virtual ~Expression() = default;

    virtual void accept(Visitor* visitor) = 0;
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator