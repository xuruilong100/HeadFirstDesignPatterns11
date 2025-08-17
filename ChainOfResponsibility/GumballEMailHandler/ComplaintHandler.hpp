#pragma once

#include <algorithm>
#include <cctype>
#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class ComplaintHandler : public Handler {
   public:
    explicit ComplaintHandler(const std::shared_ptr<Handler>& successor)
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

        if (std::string::npos != request.find("bruisin")) {
            value = true;
        } else if (std::string::npos != request.find("frosted")) {
            value = true;
        } else if (std::string::npos != request.find("no where")) {
            value = true;
        } else if (std::string::npos != request.find("rattle my cage")) {
            value = true;
        } else if (std::string::npos != request.find("tale nightingale")) {
            value = true;
        }
        return value;
    }

    void print() const override {
        std::cout << std::endl << "Hate mail, send to Legal:";
        Handler::print();
    }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler