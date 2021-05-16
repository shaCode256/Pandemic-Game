#include "Medic.hpp"

using namespace pandemic;

Medic &Medic::treat(City cityTo) {
    if(cityTo==currentCity){
if (gameBoard.citiesMap[currentCity].diseaseLevel == 0)
    {
        throw std::invalid_argument("This city is already cured.");
    }
    if (gameBoard.citiesMap[currentCity].cure_found)
    {
        gameBoard.citiesMap[currentCity].diseaseLevel = 0;
    }
    else
    {
        gameBoard.citiesMap[currentCity].diseaseLevel = 0;
    }
    }
    else{
        throw std::invalid_argument ("this is not the city you're in");
    }
    return *this;
}