#include "Scientist.hpp"

using namespace pandemic;

// מדענית - Scientist: יכולה לבצע 
// פעולת "גילוי תרופה" בעזרת n קלפים בלבד (במקום 5), 
// כאשר הפרמטר n מועבר בבנאי (במשחק המקורי n=4).

Scientist &Scientist::discover_cure(Color color) {
 //if there was already a cure found to this desease (color)
    if (gameBoard.citiesMap[currentCity].cure_found)
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
            //if there are at least n cards of this color
            if (numCards - gameBoard.scientist_num_cards_discover_cure >= 0)
            {
                int toDelete = gameBoard.scientist_num_cards_discover_cure;
                std::map<City, int>::iterator iter = cards.begin();
                std::map<City, int>::iterator endIter = cards.end();
                 while (iter != endIter && toDelete>0)
                {
                        City name = iter->first;
                        if (gameBoard.citiesMap[name].color == color)
                        {
                            iter->second = 0; //amount
                            toDelete--;
                        }
                iter++;
                }
                }
                gameBoard.cures_found[gameBoard.citiesMap[currentCity].color] = true; //you found the cure!
        }
        else
        {
                throw std::invalid_argument("Scientist discover_cure error: You don't have enough cards of this city");
        }
    }
    return *this;
}