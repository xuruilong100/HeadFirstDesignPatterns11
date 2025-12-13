#pragma once

#include <iostream>

namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator {
class Variable {
   private:
    std::string _name;
    int _value;

   public:
    explicit Variable(std::string_view name) : _name(name), _value(-1) {
        srand(42);
    };

    const std::string& name() const { return _name; }
    // return a boolean result based on a random number to simulate processing;
    // however, initial evaluation returns true so 'while' statements execute
    // at least one time.
    bool evaluate() {
        std::cout << "evaluating (" << _name.c_str() << ")...";

        if (0 > _value)  // initial evaluation, so...
            _value = 1;  // indicate 'true'
        else
            _value = (rand() % 100) % 3;

        if (0 == _value) {
            std::cout << "'false'" << std::endl;
            return false;
        } else {
            std::cout << "'true'" << std::endl;
            return true;
        }
    }
};
}  // namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator