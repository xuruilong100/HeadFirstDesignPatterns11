#pragma once

#include <iostream>
#include <memory>
#include "ComplaintHandler.hpp"
#include "FanHandler.hpp"
#include "LastHandler.hpp"
#include "NewLocationHandler.hpp"
#include "SpamHandler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class Client {
   private:
    std::shared_ptr<Handler> _lastHandler;
    std::shared_ptr<Handler> _newHandler;
    std::shared_ptr<Handler> _hateHandler;
    std::shared_ptr<Handler> _fanHandler;
    std::shared_ptr<Handler> _spamHandler;

   public:
    Client() {
        _lastHandler = std::make_shared<LastHandler>(nullptr);
        _newHandler = std::make_shared<NewLocationHandler>(_lastHandler);
        _hateHandler = std::make_shared<ComplaintHandler>(_newHandler);
        _fanHandler = std::make_shared<FanHandler>(_hateHandler);
        _spamHandler = std::make_shared<SpamHandler>(_fanHandler);
    }

    Client(const Client&) = delete;
    void operator=(const Client&) = delete;

    void handleRequest(std::string_view request) const {
        _spamHandler->handleRequest(request);
    }

    void print() const { _spamHandler->print(); }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler