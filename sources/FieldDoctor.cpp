#include "FieldDoctor.hpp"

using namespace pandemic;

// רופא שטח - FieldDoctor: יכול לבצע פעולת "טיפול במחלה"
//  לא רק בעיר שהוא
//   נמצא בה 
//   אלא בכל עיר סמוכה לעיר שהוא נמצא בה
//    (ע"פ מפת הקשרים), בלי להשליך קלף עיר.

FieldDoctor &FieldDoctor::treat(City cityTo)
{
    if (cityTo == currentCity || gameBoard.cities_connections.at(currentCity).find(cityTo) != gameBoard.cities_connections.at(currentCity).end())
    {
        if (gameBoard.citiesMap[cityTo].diseaseLevel == 0)
        {
            throw std::invalid_argument("FieldDoctor treat error: This city is already cured.");
        }
        if (gameBoard.cures_found[gameBoard.citiesMap[cityTo].color])
        {
            gameBoard.citiesMap[cityTo].diseaseLevel = 0;
        }
        else
        {
            gameBoard.citiesMap[cityTo].diseaseLevel -= 1;
        }
    }
    else
    {
        // gameBoard.citiesMap[cityTo].diseaseLevel -= 1;
        throw std::invalid_argument("Field_doctor treat error: this in not your city/ neighbor city"); //ALTHOUGH IT SHOULD BE
    }
    return *this;
}