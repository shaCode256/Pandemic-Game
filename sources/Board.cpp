#include "Board.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
// #define ENUM_TO_STR(ENUM) std::string(#ENUM)

using namespace pandemic;

namespace pandemic
{
    int& Board::operator[](pandemic::City city)
    { //toCheck
        return Board::citiesMap[city].diseaseLevel;
    }

    // void &Board::operator[](pandemic::City city, int num) {
    //     citiesMap[city].diseaseLevel= num;
    // }

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
        std::map<City, CityClass>::iterator iter = board.citiesMap.begin();
        std::map<City, CityClass>::iterator endIter = board.citiesMap.end();
        std::string boardDesc;
        for (; iter != endIter; ++iter)
        {  
            CityClass value = iter->second;
            boardDesc+= "cityName: "+ value.name+ ", Desease level is: " +std::to_string(value.diseaseLevel) +", ";
        }
        return std::operator<<(outStream, boardDesc);
    }
};