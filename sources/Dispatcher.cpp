#include "Dispatcher.hpp"

using namespace pandemic;

// קצין תעבורה - Dispatcher: כשהוא נמצא בתחנת-מחקר,
// הוא יכול לבצע פעולת "טיסה ישירה" לכל עיר שהוא רוצה,
//  ללא השלכת קלף-עיר.

Dispatcher &Dispatcher::fly_direct(City cityTo)
{
    if (cityTo == currentCity){
        throw std::invalid_argument("Dispatcher fly_direct error: can't fly from city to itself");
    }
    if (gameBoard.citiesMap[currentCity].research_lab_exist)
    {
        currentCity = cityTo;
    }
    else
    {
        if (cards[cityTo] == 1)
        {
            cards[cityTo] = 0;
            currentCity = cityTo;
        }
        else
        {
            throw std::invalid_argument("Dispatcher fly_direct error: you don't have a research lab in this city AND you have no card");
        }
    }
    return *this;
}