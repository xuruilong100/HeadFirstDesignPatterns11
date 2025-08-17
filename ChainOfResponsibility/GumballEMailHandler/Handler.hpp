#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <string>

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class Handler {
   private:
    std::list<std::string> _requests;
    std::shared_ptr<Handler> _successor;

   protected:
    explicit Handler(std::shared_ptr<Handler> successor)
        : _successor(std::move(successor)) {}

   public:
    Handler(const Handler&) = delete;
    void operator=(const Handler&) = delete;

    virtual ~Handler() = default;

    virtual void handleRequest(std::string_view request) {
        if (_successor) {
            _successor->handleRequest(request);
        }
    }

    virtual bool canHandleRequest(std::string_view request) {
        _requests.emplace_back(request);
        return true;
    }

    virtual void print() const = 0 {
        std::cout << " count=" << _requests.size() << std::endl;
        auto iterator = _requests.begin();
        while (iterator != _requests.end()) {
            std::cout << " - " << (*iterator) << std::endl;
            iterator++;
        }
        if (_successor) {
            _successor->print();
        }
    }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler