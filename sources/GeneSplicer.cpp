#include "GeneSplicer.hpp"

using namespace pandemic;

const int numCardsToFindCure = 5;

// פורסת גנים - GeneSplicer: יכולה לבצע פעולת "גילוי תרופה"
//  בעזרת 5 קלפים כלשהם -
//  לא דווקא מהצבע של המחלה.

GeneSplicer &GeneSplicer::discover_cure(Color color)
{
    //if there was already a cure found to this desease (color)
    if (gameBoard.cures_found[color])
    {
        //no need to throw exception();
    }
    else
    {
        if (gameBoard.citiesMap[currentCity].research_lab_exist) //if there's a lab
        {
            int numCards = 0;
            //counting how many cards there are to this player in this color
            std::map<City, int>::iterator iter = Player::cards.begin();
            std::map<City, int>::iterator endIter = Player::cards.end();
            for (; iter != endIter; ++iter)
            {
                if (iter->second == 1)
                {
                    numCards++;
                }
                if(numCards==numCardsToFindCure){
                    break;
                }
            }
            //if there are at least 5 cards (NOT only of this color)
            iter = Player::cards.begin();
            endIter = Player::cards.end();
            if (numCards - numCardsToFindCure >= 0)
            {
                int toDelete = numCardsToFindCure;
                while (iter != endIter && toDelete > 0)
                {
                    if (iter->second == 1)
                    {
                        iter->second = 0; //amount of cards
                        toDelete--;
                    }
                    iter++;
                }
                gameBoard.cures_found[color]=true; //Find the cure!
            }
            else
            {
                throw std::invalid_argument("GeneSplicer discover_cure error: You don't have enough city cards");
            }
        }
        else
        {
            throw std::invalid_argument("GeneSplicer discover_cure error: There's no lab");
        }
    }
    return *this;
}