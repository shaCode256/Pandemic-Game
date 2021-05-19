#include "Researcher.hpp"
const int numCardsToFindCure = 5;
using namespace pandemic;

// חוקרת - Researcher: יכולה לבצע פעולת "גילוי תרופה" בכל עיר -
// לא חייבת להיות בתחנת מחקר.

Researcher &Researcher::discover_cure(Color color)
{
    //if there was already a cure found to this desease (color)
    if (gameBoard.citiesMap[currentCity].cure_found)
    {
        //no need to throw exception();
    }
    else
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
                if (iter->second == 1)
                {
                    numCards++;
                }
            }
        }
        //if there are at least 5 cards of this color
        if (numCards - numCardsToFindCure >= 0)
        {
            int toDelete = numCardsToFindCure;
            std::map<City, int>::iterator iter = cards.begin();
            std::map<City, int>::iterator endIter = cards.end();
            while (iter != endIter && toDelete > 0)
            {
                City name = iter->first;
                if (gameBoard.citiesMap[name].color == color && iter->second == 1)
                {
                    iter->second = 0; //amount
                    toDelete--;
                }
                iter++;
            }
            gameBoard.cures_found[gameBoard.citiesMap[currentCity].color] = true; //you found the cure!
        }
        else
        {
            throw std::invalid_argument("Researcher discover_cure error: You don't have enough cards with this color");
        }
    }
    return *this;
}