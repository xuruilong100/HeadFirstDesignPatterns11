#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Expression.hpp"
#include "Variable.hpp"
#include "Visitor.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class WhileCommand : public Expression {
   private:
    std::shared_ptr<Variable> _variable;
    std::vector<std::string> _expression;

   public:
    WhileCommand(std::shared_ptr<Variable> variable,
                 std::vector<std::string> expression)
        : _variable(std::move(variable)), _expression(std::move(expression)) {}

    ~WhileCommand() = default;

    void accept(Visitor* visitor) override { visitor->interpret(this); }

    bool evaluate() {
        bool value = _variable->evaluate();
        return value;
    }

    const auto& variable() const { return _variable->name(); }

    const auto& expression() const { return _expression; }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator