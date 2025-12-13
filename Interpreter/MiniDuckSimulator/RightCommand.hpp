#pragma once

#include "Expression.hpp"
#include "Visitor.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class RightCommand : public Expression {
   public:
    void accept(Visitor* visitor) override { visitor->interpret(this); }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator