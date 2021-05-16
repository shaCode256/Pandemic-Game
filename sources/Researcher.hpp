#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Researcher : public Player
    {
    public:
        Researcher &discover_cure(Color color);
        Researcher (Board &board, City city) : Player(board, city)
        {
        }
        std::string role()
        {
            return "Researcher";
        }
    };
}