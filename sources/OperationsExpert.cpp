#include "OperationsExpert.hpp"

using namespace pandemic;

// קצין מבצעים - OperationsExpert:יכול לבצע פעולת "בנייה" בכל עיר
//  שהוא נמצא בה, בלי להשליך קלף-עיר מתאים.

OperationsExpert &OperationsExpert::build() {
    gameBoard.citiesMap[currentCity].research_lab_exist= true;
    return *this;
}