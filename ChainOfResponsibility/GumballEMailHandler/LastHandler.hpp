#pragma once

#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class LastHandler : public Handler {
   public:
    explicit LastHandler(const std::shared_ptr<Handler>& successor)
        : Handler(successor) {}

    void handleRequest(std::string_view request) override {
        Handler::canHandleRequest(request);
    }

    void print() const override {
        std::cout << std::endl << "Unclassified, send to AI team:";
        Handler::print();
    }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler