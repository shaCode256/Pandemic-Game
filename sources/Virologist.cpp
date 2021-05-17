#include "Virologist.hpp"

using namespace pandemic;

Virologist &Virologist::treat(City cityTo)
{
    if (gameBoard.citiesMap[cityTo].diseaseLevel == 0)
    {
        throw std::invalid_argument("This city is already cured.");
    }
    if (cityTo == currentCity || cards[cityTo] > 0)
    {
        if (cityTo == currentCity)
        {
            if (gameBoard.citiesMap[cityTo].cure_found)
            {
                gameBoard.citiesMap[cityTo].diseaseLevel = 0;
            }
            else
            {
                gameBoard.citiesMap[cityTo].diseaseLevel -= 1;
            }
        }
        else
        {
            cards[cityTo] = 0;
        }
    }
    else
    {
        throw std::invalid_argument("Virolofist treat error: you have no card of this city");
    }
    return *this;
}