#pragma once
#include "Player.hpp"

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        FieldDoctor &build();
        FieldDoctor (Board &board, City city) : Player(board, city)
        {
        }
        std::string role()
        {
            return "FieldDoctor";
        }
    };
}