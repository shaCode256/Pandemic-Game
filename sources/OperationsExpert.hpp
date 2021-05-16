#pragma once
#include "Player.hpp"

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        OperationsExpert &build();
        OperationsExpert(Board &board, City city) : Player(board, city)
        {
        }
        std::string role()
        {
            return "OperationsExpert";
        }
    };
}