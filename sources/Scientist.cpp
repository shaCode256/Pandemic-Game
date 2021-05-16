#include "Scientist.hpp"

using namespace pandemic;

Scientist &Scientist::discover_cure(Color color) {
 //if there was already a cure found to this desease (color)
    if (gameBoard.citiesMap[currentCity].cure_found)
    {
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
            //if there are at least n cards of this color
            if (numCards - gameBoard.scientist_num_cards_discover_cure >= 0)
            {
                int toDelete = gameBoard.scientist_num_cards_discover_cure;
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
                gameBoard.citiesMap[currentCity].diseaseLevel = 0; //cure the desease!
            }
            else
            {
                throw std::invalid_argument("You don't have enough cards of this city");
            }
        }
    }
    return *this;
}