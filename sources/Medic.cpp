#include "Medic.hpp"

using namespace pandemic;

Medic &Medic::treat(City cityTo)
{
    if (cityTo == currentCity)
    {
        if (gameBoard.citiesMap[currentCity].diseaseLevel == 0)
        {
            throw std::invalid_argument("This city is already cured.");
        }
        else
        {
            gameBoard.citiesMap[currentCity].diseaseLevel = 0;
        }
    }
    else
    {
        throw std::invalid_argument("this is not the city you're in");
    }
    return *this;
}

//for the moving: added - 
// אם כבר התגלתה תרופה למחלה, הוא אוטומטית מוריד את
// כל קוביות-המחלה מכל עיר שהוא נכנס אליה, גם בלי לבצע פעולת "טיפול במחלה"

Medic &Medic::fly_shuttle(City cityTo)
{
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't fly to where you're already at");
    }
    if (gameBoard.citiesMap[currentCity].research_lab_exist && gameBoard.citiesMap[cityTo].research_lab_exist)
    {
        currentCity = cityTo;
        if (gameBoard.cures_found[gameBoard.citiesMap[cityTo].color])
        {
            gameBoard.citiesMap[cityTo].diseaseLevel = 0;
        }
    }
    else
    {
        throw std::invalid_argument("you can't shuttle fly to this city. at least one of the cities (yours and the desired one) doesn't have a lab");
    }
    return *this;
}
Medic &Medic::fly_direct(City cityTo)
{
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't fly to where you're already at");
    }
    if (cards[cityTo] == 1)
    {
        cards[cityTo] = 0;
        currentCity = cityTo;
        if (gameBoard.cures_found[gameBoard.citiesMap[cityTo].color])
        {
            gameBoard.citiesMap[cityTo].diseaseLevel = 0;
        }
    }
    else
    {
        throw std::invalid_argument("you can't fly to a city you don't hold its card");
    }
    return *this;
};
Medic &Medic::fly_charter(City cityTo)
{
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't fly to where you're already at");
    }
    if (cards[currentCity] == 1)
    {
        cards[currentCity] = 0;
        currentCity = cityTo;
        if (gameBoard.cures_found[gameBoard.citiesMap[cityTo].color])
        {
            gameBoard.citiesMap[cityTo].diseaseLevel = 0;
        }
    }
    return *this;
};
Medic &Medic::drive(City cityTo)
{
    // std::string cityString = ENUM_TO_STR(cityTo);
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't drive to where you're already at");
    }
    if (gameBoard.cities_connections[currentCity].find(cityTo) != gameBoard.cities_connections[currentCity].end())
    {
        currentCity = cityTo;
        if (gameBoard.cures_found[gameBoard.citiesMap[cityTo].color])
        {
            gameBoard.citiesMap[cityTo].diseaseLevel = 0;
        }
    }
    else
    {
        throw std::invalid_argument("you can't drive to this city. it's not a neighbor city");
    }
    return *this;
};