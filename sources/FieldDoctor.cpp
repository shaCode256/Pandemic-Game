#include "FieldDoctor.hpp"

using namespace pandemic;

FieldDoctor &FieldDoctor::treat(City cityTo)
{
    if (cityTo == currentCity || gameBoard.cities_connections[currentCity].find(cityTo) != gameBoard.cities_connections[currentCity].end())
    {
        if (gameBoard.citiesMap[cityTo].diseaseLevel == 0)
        {
            throw std::invalid_argument("This city is already cured.");
        }
        if (gameBoard.cures_found[gameBoard.citiesMap[cityTo].color])
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
        // gameBoard.citiesMap[cityTo].diseaseLevel -= 1;
        throw std::invalid_argument("this in not your city/ neighbor city"); //ALTHOUGH IT SHOULD BE
    }
    return *this;
}