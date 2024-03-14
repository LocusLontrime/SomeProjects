#include <iostream>
#include "lib.h"

#define DAYWEEK(number) DAY_##number
#define DAY_1 "Monday"
#define DAY_2 "Tuesday"
#define DAY_3 "Wednesday"
#define DAY_4 "Thursday"
#define DAY_5 "Friday"
#define DAY_6 "Saturday"
#define DAY_7 "Sunday"

void task1() {
    int number;
    std::cout << "Enter the number day of week: ";
    std::cin >> number;
    if (number == 1)
        std::cout << "Today is " << DAYWEEK(1) << std::endl;
    else if (number == 2)
        std::cout << "Today is " << DAYWEEK(2) << std::endl;
    else if (number == 3)
        std::cout << "Today is " << DAYWEEK(3) << std::endl;
    else if (number == 4)
        std::cout << "Today is " << DAYWEEK(4) << std::endl;
    else if (number == 5)
        std::cout << "Today is " << DAYWEEK(5) << std::endl;
    else if (number == 6)
        std::cout << "Today is " << DAYWEEK(6) << std::endl;
    else if (number == 7)
        std::cout << "Today is " << DAYWEEK(7) << std::endl;
    else
        std::cout << "Incorrect input!" << std::endl;
}