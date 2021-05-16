#include "Dispatcher.hpp"

using namespace pandemic;

Dispatcher &Dispatcher::fly_direct(City cityTo) {
    if(gameBoard.citiesMap[currentCity].research_lab_exist){
    currentCity=cityTo;
    }
    else{
        throw std::invalid_argument("you don't have a research lab in this city");
    }
    return *this;
}