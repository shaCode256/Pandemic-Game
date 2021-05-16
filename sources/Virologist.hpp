#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
    public:
        Virologist &treat(City cityTo);
        Virologist(Board &board, City city) : Player(board, city)
        {
        }
        std::string role()
        {
            return "Virologist";
        }
    };
}