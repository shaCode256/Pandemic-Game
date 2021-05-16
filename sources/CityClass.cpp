#include "Board.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include "CityClass.hpp"

using namespace pandemic;

namespace pandemic
{
        City name;
        int diseaseLevel;
        Color color;
        bool cure_found=false;
        bool research_lab_exist=false;
        // friend std::ostream &operator<<(std::ostream &outStream, Board &board){
        // outStream << "name: " << city.name << ", diseaseLevel: " << city.diseaseLevel;
        // return outStream;
        // }
};