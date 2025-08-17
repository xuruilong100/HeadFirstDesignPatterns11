#pragma once

#include <algorithm>
#include <cctype>
#include "Handler.hpp"

namespace HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler {
class FanHandler : public Handler {
   public:
    explicit FanHandler(const std::shared_ptr<Handler>& successor)
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

        if (std::string::npos != request.find("razz")) {
            value = true;
        } else if (std::string::npos != request.find("hip")) {
            value = true;
        } else if (std::string::npos != request.find("radioactive")) {
            value = true;
        } else if (std::string::npos != request.find("blast")) {
            value = true;
        } else if (std::string::npos != request.find("boss")) {
            value = true;
        } else if (std::string::npos != request.find("orbit")) {
            value = true;
        } else if (std::string::npos != request.find("kick")) {
            value = true;
        }
        return value;
    }

    void print() const override {
        std::cout << std::endl << "Fan mail, send to CEO:";
        Handler::print();
    }
};
}  // namespace
   // HeadFirstDesignPatterns::ChainOfResponsibility::GumballEMailHandler