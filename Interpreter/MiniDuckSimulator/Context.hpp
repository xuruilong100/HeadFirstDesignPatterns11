#pragma once

#include <list>
#include <memory>
#include <string>
#include <vector>
#include "DisplayCommand.hpp"
#include "Expression.hpp"
#include "FlyCommand.hpp"
#include "LeftCommand.hpp"
#include "QuackCommand.hpp"
#include "RightCommand.hpp"
#include "SwimCommand.hpp"
#include "Variable.hpp"
#include "WhileCommand.hpp"

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
// Grammar:
//
//   expression	::= <command> | <sequence> | <repetition>
//   sequence	::= <expression> ';' <command>
//   command		::= left | right | display | fly | quack | swim
//   repetition	::= while '(' <variable> ')' '{' <expression> '}'
//   variable	::= [A-Z,a-z]+

class Context {
   private:
    std::list<std::shared_ptr<Expression>> _content;

   public:
    explicit Context(const std::vector<std::string>& tokens) {
        auto iterator = tokens.begin();

        while (iterator != tokens.end()) {
            if (0 == iterator->compare("display"))
                _content.emplace_back(new DisplayCommand);
            else if (0 == iterator->compare("fly"))
                _content.emplace_back(new FlyCommand());
            else if (0 == iterator->compare("quack"))
                _content.emplace_back(new QuackCommand());
            else if (0 == iterator->compare("left"))
                _content.emplace_back(new LeftCommand());
            else if (0 == iterator->compare("right"))
                _content.emplace_back(new RightCommand());
            else if (0 == iterator->compare("swim"))
                _content.emplace_back(new SwimCommand());
            else if (0 == iterator->compare("while")) {
                std::vector<std::string> expression;
                std::shared_ptr<Variable> variable;
                bool open_paren_found = false;
                bool open_brace_found = false;
                while (++iterator != tokens.end()) {
                    if (0 == iterator->compare("("))
                        open_paren_found = true;
                    else if (0 == iterator->compare(")"))
                        continue;
                    else if (0 == iterator->compare("{"))
                        open_brace_found = true;
                    else if (0 == iterator->compare("}"))
                        break;
                    else if (0 == variable && true == open_paren_found)
                        variable = std::make_shared<Variable>(*iterator);
                    else {
                        expression.push_back(*iterator);
                        if (true == open_brace_found)
                            continue;
                        else
                            break;
                    }
                }
                _content.emplace_back(new WhileCommand(variable, expression));
            }
            ++iterator;
        }
    }

    auto begin() { return _content.begin(); }
    auto end() { return _content.end(); }

    auto cbegin() const { return _content.cbegin(); }
    auto cend() const { return _content.cend(); }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator