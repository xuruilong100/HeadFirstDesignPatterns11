#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include "Planner.hpp"
#include "VacationBuilder.hpp"

namespace HeadFirstDesignPatterns::Builder {
class Client {
   private:
    std::shared_ptr<VacationBuilder> _builder;

    int promptUser(std::string_view prompt) const {
        int value = 0;
        std::cout << prompt << std::endl;
        std::cin >> value;
        return value;
    }

   public:
    explicit Client(std::shared_ptr<VacationBuilder> builder)
        : _builder(std::move(builder)) {}

    Client(const Client&) = delete;
    void operator=(const Client&) = delete;

    std::shared_ptr<Vacation> constructPlanner() {
        std::chrono::year_month_day local;
        int tm_year;
        unsigned int tm_mon;
        unsigned int tm_mday;

        do {
            std::cout << std::endl
                      << "Enter vacation date (YYYY MM DD) where..."
                      << std::endl;
            std::cout << "YYYY=2006, 2007, etc..., MM=1-12, DD=1-31, separated "
                         "by spaces"
                      << std::endl;
            std::cout << "YYYY MM DD" << std::endl;
            std::cin >> tm_year >> tm_mon >> tm_mday;

            local = std::chrono::year_month_day{std::chrono::year{tm_year},
                                                std::chrono::month{tm_mon},
                                                std::chrono::day{tm_mday}};

            _builder->buildDay(local);

            switch (promptUser(
                "hotel? (0=No, 1=Grand Facadion, 2=Nostalgic Momento)")) {
                case 1:
                    _builder->addHotel(hotelGrandFacadion);
                    break;
                case 2:
                    _builder->addHotel(hotelNostalgicMomento);
                    break;
                default:
                    std::cout << "No hotel selected." << std::endl;
                    break;
            }

            switch (promptUser("Park tickets? (0=No, 1=Yes)")) {
                case 1:
                    _builder->addTickets(ticketPark);
                    break;
                default:
                    std::cout << "No park tickets selected." << std::endl;
                    break;
            }

            switch (
                promptUser("Dinner Reservations? (0=No, 1=Pancake House, "
                           "2=Objectville Diner)")) {
                case 1:
                    _builder->addReservations(dinnerPancakeHouse);
                    break;
                case 2:
                    _builder->addReservations(dinnerObjectvilleDiner);
                    break;
                default:
                    std::cout << "No dinner reservations selected."
                              << std::endl;
                    break;
            }

            switch (
                promptUser("Special Events? (0=No, 1=Choc-O-Holic factory "
                           "tour, 2=Pizza factory tour)")) {
                case 1:
                    _builder->addSpecialEvent(specialChocolateFactoryTour);
                    break;
                case 2:
                    _builder->addSpecialEvent(specialPizzaFactoryTour);
                    break;
                default:
                    std::cout << "No special events selected." << std::endl;
                    break;
            }
        } while (promptUser(
                     "Would you like to plan another day? (0=No, 1=Yes)") == 1);

        return _builder->getVacationPlanner();
    }
};
}  // namespace HeadFirstDesignPatterns::Builder