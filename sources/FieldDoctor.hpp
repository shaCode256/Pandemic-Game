#pragma once
#include "Player.hpp"

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        FieldDoctor &treat(City cityTo);
        FieldDoctor (Board &board, City city) : Player(board, city)
        {
        }
        std::string role()
        {
            return "FieldDoctor";
        }
    };
}