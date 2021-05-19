#pragma once

namespace pandemic{
    enum Color{
        Black,
        Blue,
        Red,
        Yellow
    };

    inline const char* ToString(Color color)
{
    switch (color)
    {
        case Black:   return "Black";
        case Blue:   return "Blue";
        case Red: return "Red";
        default:      return "Yellow";
    }
}

}

//Reference:
//https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string