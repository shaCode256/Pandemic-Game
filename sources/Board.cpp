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
    int &Board::operator[](pandemic::City city)
    { //toCheck
        return citiesMap[city].diseaseLevel;
    }

    // void &Board::operator[](pandemic::City city, int num) {
    //     citiesMap[city].diseaseLevel= num;
    // }

    std::ostream &operator<<(std::ostream &outStream, Board &board)
    {
        std::map<City, CityClass>::iterator iter = board.citiesMap.begin();
        std::map<City, CityClass>::iterator endIter = board.citiesMap.end();
        for (; iter != endIter; ++iter)
        {
            City key = iter->first;
            CityClass value = iter->second;
        }
        return outStream;
    }
};