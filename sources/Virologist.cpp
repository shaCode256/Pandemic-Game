#include "Virologist.hpp"

using namespace pandemic;

Virologist &Virologist::treat(City cityTo)
{
    if (cityTo == currentCity || gameBoard.cities_connections[currentCity].find(cityTo)!= gameBoard.cities_connections[currentCity].end()){
        if(cards[cityTo]==1){
    if (gameBoard.citiesMap[cityTo].diseaseLevel == 0)
    {
        throw std::invalid_argument("This city is already cured.");
    }
    if (gameBoard.citiesMap[cityTo].cure_found)
    {
        gameBoard.citiesMap[cityTo].diseaseLevel = 0;
    }
    else
    {
        gameBoard.citiesMap[cityTo].diseaseLevel -= 1;
    }
    }
    }
    else{
        throw std::invalid_argument("you have no card of this city");
    }
    return *this;

}