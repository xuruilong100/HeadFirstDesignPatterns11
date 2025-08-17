#include "Client.hpp"
#include "VacationBuilder.hpp"

using namespace HeadFirstDesignPatterns::Builder;

int main() {
    Client client(std::make_shared<VacationBuilder>());

    std::shared_ptr<Vacation> vacation(client.constructPlanner());
    vacation->printItinerary();

    return EXIT_SUCCESS;
}

// Output:
/*
Welcome to Patternsland Vacation Planner!

Enter vacation date (YYYY MM DD) where...
YYYY=2006, 2007, etc..., MM=1-12, DD=1-31, separated by spaces
YYYY MM DD
2025 01 01
hotel? (0=No, 1=Grand Facadion, 2=Nostalgic Momento)
1
Park tickets? (0=No, 1=Yes)
1
Dinner Reservations? (0=No, 1=Pancake House, 2=Objectville Diner)
1
Special Events? (0=No, 1=Choc-O-Holic factory tour, 2=Pizza factory tour)
1
Would you like to plan another day? (0=No, 1=Yes)
1

Enter vacation date (YYYY MM DD) where...
YYYY=2006, 2007, etc..., MM=1-12, DD=1-31, separated by spaces
YYYY MM DD
2025 01 02
hotel? (0=No, 1=Grand Facadion, 2=Nostalgic Momento)
0
Park tickets? (0=No, 1=Yes)
0
Dinner Reservations? (0=No, 1=Pancake House, 2=Objectville Diner)
0
Special Events? (0=No, 1=Choc-O-Holic factory tour, 2=Pizza factory tour)
0
Would you like to plan another day? (0=No, 1=Yes)
0

  Vacation Itinerary, All events
2025-1-1 :   Day, 1
   Hotel , Grand Facadion- $399
   Tickets , Park tickets- $75
  Reservation, Dinner
  Reservation, Special event
2025-1-2 :   Day, 2

Goodbye and have a dreamy vacation!
*/