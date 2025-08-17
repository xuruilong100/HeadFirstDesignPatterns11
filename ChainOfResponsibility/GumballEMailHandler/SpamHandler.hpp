#pragma once

#include <algorithm>
#include <cctype>
#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class SpamHandler : public Handler {
   public:
    explicit SpamHandler(const std::shared_ptr<Handler>& successor)
        : Handler(successor) {}

    void handleRequest(std::string_view request) override {
        std::string req(request);
        std::transform(request.begin(), request.end(), req.begin(), tolower);

        if (canHandleRequest(req) == true) {
            Handler::canHandleRequest(req);
        } else {
            Handler::handleRequest(req);
        }
    }

    bool canHandleRequest(std::string_view request) override {
        bool value = false;

        if (std::string::npos != request.find("bread")) {
            value = true;
        } else if (std::string::npos != request.find("buzzin")) {
            value = true;
        } else if (std::string::npos != request.find("cuzzin")) {
            value = true;
        } else if (std::string::npos != request.find("eyeball")) {
            value = true;
        }
        return value;
    }

    void print() const override {
        std::cout << std::endl << "Spam mail, send to shredder:";
        Handler::print();
    }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler