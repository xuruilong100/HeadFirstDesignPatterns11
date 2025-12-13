#pragma once

#include <memory>

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class QuackCommand;
class FlyCommand;
class LeftCommand;
class RightCommand;
class DisplayCommand;
class SwimCommand;
class WhileCommand;
class Variable;

class Visitor {
   public:
    Visitor() = default;
    virtual ~Visitor() = default;

    virtual void interpret(DisplayCommand* command) = 0;
    virtual void interpret(QuackCommand* command) = 0;
    virtual void interpret(FlyCommand* command) = 0;
    virtual void interpret(LeftCommand* command) = 0;
    virtual void interpret(RightCommand* command) = 0;
    virtual void interpret(SwimCommand* command) = 0;
    virtual void interpret(WhileCommand* command) = 0;
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator