#include "GeneSplicer.hpp"

using namespace pandemic;

const int numCardsToFindCure = 5;

// פורסת גנים - GeneSplicer: יכולה לבצע פעולת "גילוי תרופה"
//  בעזרת 5 קלפים כלשהם -
//  לא דווקא מהצבע של המחלה.

GeneSplicer &GeneSplicer::discover_cure(Color Color)
{
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
                numCards++;
            }
            //if there are at least 5 cards (NOT only of this color)
            if (numCards - numCardsToFindCure >= 0)
            {
                int toDelete = numCardsToFindCure;
                while (iter != endIter && toDelete > 0)
                {
                    iter->second = 0; //amount of cards
                    toDelete--;
                    iter++;
                }
                gameBoard.citiesMap[currentCity].diseaseLevel = 0; //cure the desease!
            }
            else
            {
                throw std::invalid_argument("GeneSplicer discover_cure error: You don't have enough city cards");
            }
        }
    }
    return *this;
}