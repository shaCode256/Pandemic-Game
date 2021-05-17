#pragma once
#include "Board.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>

namespace pandemic
{
    class CityClass
    {
    public:
        std::string name;
        int diseaseLevel;
        Color color;
        bool cure_found;
        bool research_lab_exist;
        CityClass(){}; 

    CityClass(std::string name_, Color color_){
        diseaseLevel=0;
        cure_found=false;
        research_lab_exist=false;
        name= name_;
        color= color_;
    }
        // friend std::ostream &operator<<(std::ostream &outStream, pandemic::Board &board){
        //    return outStream; 
        // };
    };
};