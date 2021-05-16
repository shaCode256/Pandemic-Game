#pragma once
#include "Player.hpp"

namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
        GeneSplicer &discover_cure(Color color);
        GeneSplicer (Board &board, City city) : Player(board, city)
        {
        }
        std::string role()
        {
            return "GeneSplicer";
        }
    };
}