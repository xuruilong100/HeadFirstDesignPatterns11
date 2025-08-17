#pragma once

#include <chrono>
#include <memory>
#include "Vacation.hpp"

namespace HeadFirstDesignPatterns::Builder {
class Builder {
   public:
    Builder() = default;
    virtual ~Builder() = default;

    virtual void buildDay(const std::chrono::year_month_day& date) = 0;
    virtual void addHotel(const std::string& hotel) = 0;
    virtual void addTickets(const std::string& event) = 0;
    virtual void addReservations(const std::string& event) = 0;
    virtual void addSpecialEvent(const std::string& event) = 0;
    virtual std::shared_ptr<Vacation> getVacationPlanner() = 0;
};
}  // namespace HeadFirstDesignPatterns::Builder