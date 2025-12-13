#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include "DuckFactory.hpp"
#include "Interpreter.hpp"

using namespace HeadFirstDesignPatterns::Interpreter::MiniDuckSimulator;

void lexer(std::istream_iterator<char> next,
           std::istream_iterator<char> last,
           std::vector<std::string>& tokens) {
    std::string token;
    while (next != last) {
        if (*next == ';') {
            if (0 != token.length()) {
                tokens.push_back(token);
                token.clear();
            }
        } else if (*next == '(' || *next == ')' || *next == '{' ||
                   *next == '}') {
            if (0 != token.length()) {
                tokens.push_back(token);
                token.clear();
            }
            token += *next;
            tokens.push_back(token);
            token.clear();
        } else {
            token += tolower(*next);
        }
        next++;
    }
    if (0 != token.length()) {
        tokens.push_back(token);
    }
}

int main() {
    // "0=None(exit), 1=Mallard, 2=Redhead, 3=Rubber, 4=Model"
    int fowl = 2;

    std::shared_ptr<Duck> duck(DuckFactory::createDuck(fowl));
    std::vector<std::string> tokens;

    std::ifstream file("duck.txt");
    std::istream_iterator<char> next(file);
    std::istream_iterator<char> last;
    lexer(next, last, tokens);

    if (0 != tokens.size()) {
        Context context(tokens);
        Interpreter interpreter(duck);
        interpreter.interpret(context);
    }

    std::cout << "Goodbye..." << std::endl;

    return EXIT_SUCCESS;
}

// Output:
/*
I'm turning right...
evaluating (daylight)...'true'
I'm flying!!
evaluating (daylight)...'false'
Quack
Goodbye...
*/