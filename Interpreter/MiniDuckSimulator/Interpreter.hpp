#pragma once

#include <iostream>
#include <memory>
#include "Context.hpp"
#include "Duck.hpp"
#include "Visitor.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class Interpreter : public Visitor {
   private:
    std::shared_ptr<Duck> _duck;

   public:
    explicit Interpreter(std::shared_ptr<Duck> duck) : _duck(std::move(duck)) {}

    void interpret(DisplayCommand* command) { _duck->display(); }

    void interpret(FlyCommand* command) { _duck->fly(); }

    void interpret(QuackCommand* command) { _duck->quack(); }

    void interpret(SwimCommand* command) { _duck->swim(); }

    void interpret(LeftCommand* command) {
        std::cout << "I'm turning left..." << std::endl;
    }

    void interpret(RightCommand* command) {
        std::cout << "I'm turning right..." << std::endl;
    }

    void interpret(WhileCommand* command) {
        while (true == command->evaluate()) {
            Context context(command->expression());
            interpret(context);
        }
    }

    void interpret(Context& context) {
        for (auto expression = context.begin(); expression != context.end();
             ++expression) {
            (*expression)->accept(this);
        }
    };
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator