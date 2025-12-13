#pragma once

#include <memory>
#include <string>
#include "Expression.hpp"
#include "Visitor.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class NullCommand : public Expression {
   private:
    std::string _value;

   public:
    void accept(Visitor* visitor) override { return visitor->interpret(this); }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator