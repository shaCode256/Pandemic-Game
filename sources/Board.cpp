#include "Board.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>

using namespace pandemic;

namespace pandemic
{
    int& Board::operator[](pandemic::City city)
    { //toCheck
        return Board::citiesMap[city].diseaseLevel;
    }

    bool Board::is_clean()
    {
        std::map<City, CityClass>::iterator iter = Board::citiesMap.begin();
        std::map<City, CityClass>::iterator endIter = Board::citiesMap.end();
        for (; iter != endIter; ++iter)
        {
            CityClass city = iter->second;
            if (city.diseaseLevel != 0)
            {
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures()
    {
        std::map<Color, bool>::iterator iter = Board::cures_found.begin();
        std::map<Color, bool>::iterator endIter = Board::cures_found.end();
        for (; iter != endIter; ++iter)
        {
            iter->second = false;
        }
    }

    void Board::remove_stations()
    {
        std::map<City, CityClass>::iterator iter = Board::citiesMap.begin();
        std::map<City, CityClass>::iterator endIter = Board::citiesMap.end();
        for (; iter != endIter; ++iter)
        {
            iter->second.research_lab_exist = false;
        }
    }

    std::ostream &operator<<(std::ostream &outStream, Board &board)
    {
//אופרטור פלט - מציג את מצב הלוח בפורמט כלשהו לבחירתכם. מצב הלוח כולל את:
// רמת המחלה בכל אחת מהערים; V
// התרופות שהתגלו עד כה (ראו הסבר למטה);
// תחנות-מחקר שנבנו עד כה (ראו הסבר למטה)
        std::map<City, CityClass>::iterator iter = board.citiesMap.begin();
        std::map<City, CityClass>::iterator endIter = board.citiesMap.end();
        std::string boardDesc;
    
        boardDesc+= "\n ____________description start______________________________ \n"; 
        boardDesc+= "\n Cities: \n";
        boardDesc+= "\n ______ \n";

        for (; iter != endIter; ++iter)
        {  
            CityClass value = iter->second;
            boardDesc+= "\n*City's name: "+ value.name+ ", Desease level is: " +std::to_string(value.diseaseLevel) +" \n";
        }

        std::map<City, CityClass>::iterator iterLab = board.citiesMap.begin();
        std::map<City, CityClass>::iterator endIterLab = board.citiesMap.end();
        boardDesc+= "\n Research labs are available at: \n";
        boardDesc+= "\n ______________________________ \n";

        for (; iterLab != endIterLab; ++iterLab)
        {  
            if(iterLab->second.research_lab_exist){ //if cure found->second == true
            boardDesc+= "\n*";
            boardDesc+=  iterLab->second.name;
            boardDesc+= "\n";
            }
        }    

        std::map<Color, bool>::iterator iterColor = board.cures_found.begin();
        std::map<Color, bool>::iterator endIterColor = board.cures_found.end();
        boardDesc+= "\n Found cures to: \n";
        boardDesc+= "\n ___________ \n";

        for (; iterColor != endIterColor; ++iterColor)
        {  
            if(iterColor->second){ //if cure found->second == true
            boardDesc+= "\n*";
            boardDesc+=  ToString(iterColor->first);
            boardDesc+= "\n";
            }
        }

        boardDesc+= "\n __________end_____of_____description_____________________ \n"; 

        return std::operator<<(outStream, boardDesc);
    }
};