#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <stdexcept>
const int numCardsToFindCure= 5;
//#define ENUM_TO_STR(ENUM) std::string(#ENUM)
//implements the actions a player can do in this pandemic game.

using namespace pandemic;

Player &Player::build()
{
    if (gameBoard.citiesMap[currentCity].research_lab_exist)
    {
        //no need to throw exception();
    }
    else
    {
        if (cards[currentCity] == 1)
        {
            cards[currentCity] = 0;
            gameBoard.citiesMap[currentCity].research_lab_exist = true;
        }
        else
        {
            throw std::invalid_argument("You don't have enough cards of this city");
            ;
        }
    }
    return *this;
}

Player &Player::discover_cure(Color color)
{
    //if there was already a cure found to this desease (color)
    if (gameBoard.cures_found[gameBoard.citiesMap[currentCity].color])
    {
        //no need to throw exception();
    }
    else
    {
        if (gameBoard.citiesMap[currentCity].research_lab_exist) //if there's a lab
        {
            int numCards = 0;
            //counting how many cards there are to this player in this color
            std::map<City, int>::iterator iter = cards.begin();
            std::map<City, int>::iterator endIter = cards.end();
            for (; iter != endIter; ++iter)
            {
                City name = iter->first;
                if (gameBoard.citiesMap[name].color == color)
                {
                    numCards++;
                }
            }
            //if there are at least 5 cards of this color
            if (numCards - numCardsToFindCure >= 0)
            {
                int toDelete = numCardsToFindCure;
                while (toDelete > 0)
                {
                    std::map<City, int>::iterator iter = cards.begin();
                    std::map<City, int>::iterator endIter = cards.end();
                    for (; iter != endIter; ++iter)
                    {
                        City name = iter->first;
                        if (gameBoard.citiesMap[name].color == color)
                        {
                            iter->second = 0; //amount
                            toDelete--;
                        }
                    }
                }
                gameBoard.cures_found[gameBoard.citiesMap[currentCity].color] = true; //you found the cure!
            }
            else
            {
                throw std::invalid_argument("You don't have enough cards of this city");
            }
        }
        else{
            throw std::invalid_argument("There's no lab in this city");   
        }
    }
    return *this;
}

Player &Player::drive(City cityTo)
{
    // std::string cityString = ENUM_TO_STR(cityTo);
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't drive to where you're already at");
    }
    if (gameBoard.cities_connections[currentCity].find(cityTo) != gameBoard.cities_connections[currentCity].end())
    {
        currentCity = cityTo;
    }
    else
    {
        throw std::invalid_argument("you can't drive to this city. it's not a neighbor city");
    }
    return *this;
}

Player &Player::fly_charter(City cityTo)
{
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't fly to where you're already at");
    }
    if (cards[currentCity] == 1)
    {
        cards[currentCity] = 0;
        currentCity = cityTo;
    }
    return *this;
}

Player &Player::fly_direct(City cityTo)
{
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't fly to where you're already at");
    }
    if (cards[cityTo] == 1)
    {
        cards[cityTo] = 0;
        currentCity = cityTo;
    }
    else{
        throw std::invalid_argument("you can't fly to a city you don't hold its card");
    }
    return *this;
}

Player &Player::fly_shuttle(City cityTo)
{
    if (cityTo == currentCity)
    {
        throw std::invalid_argument("you can't fly to where you're already at");
    }
    if (gameBoard.citiesMap[currentCity].research_lab_exist && gameBoard.citiesMap[cityTo].research_lab_exist)
    {
        currentCity = cityTo;
    }
    else
    {
        throw std::invalid_argument("you can't shuttle fly to this city. at least one of the cities (yours and the desired one) doesn't have a lab");
    }
    return *this;
}

std::string Player::role()
{
    return "default";
}

Player &Player::take_card(City city)
{
    cards[city] = 1;
    return *this;
}

Player &Player::treat(City cityTo)
{
    if (cityTo == currentCity)
    {
        if (cards[cityTo] == 1)
        {
            if (gameBoard.citiesMap[currentCity].diseaseLevel == 0)
            {
                throw std::invalid_argument("This city is already cured.");
            }

            if (gameBoard.cures_found[gameBoard.citiesMap[currentCity].color])
            {
                cards[cityTo] = 0;
                gameBoard.citiesMap[currentCity].diseaseLevel = 0;
            }
            else
            {
                cards[cityTo] = 0;
                gameBoard.citiesMap[currentCity].diseaseLevel = gameBoard.citiesMap[currentCity].diseaseLevel - 1;
            }
        }
        else
        {
            throw std::invalid_argument("you have no card of this city");
        }
    }
    else
    {
        throw std::invalid_argument("this is not the city you're in, and you're not qualified to treat another city");
    }
    return *this;
}