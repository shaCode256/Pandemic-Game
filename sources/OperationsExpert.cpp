#include "OperationsExpert.hpp"

using namespace pandemic;

OperationsExpert &OperationsExpert::build() {
    gameBoard.citiesMap[currentCity].research_lab_exist= true;
    return *this;
}