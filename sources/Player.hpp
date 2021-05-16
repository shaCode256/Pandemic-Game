#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <vector>
#include <string>
#include <iostream>

//describes the actions a player can do in this pandemic game.

namespace pandemic
{
    class Player
    {
    private:
    public:
        Board gameBoard;
        std::map<City, int> cards;
        City currentCity;
        Player(Board board, City city){};
        ~Player() = default; //destructor

        void remove_cures();

        virtual Player &build();

        virtual Player &discover_cure(Color color);

        virtual Player &drive(City cityTo);

        virtual Player &fly_charter(City cityTo);

        virtual Player &fly_direct(City cityTo);

        virtual Player &fly_shuttle(City cityTo);

        virtual std::string role();

        virtual Player &take_card(City city);

        virtual Player &treat(City city);

        void remove_cards()
        {
            std::map<City, int>::iterator iter = cards.begin();
            std::map<City, int>::iterator endIter = cards.end();
            for (; iter != endIter; ++iter)
            {
                City name = iter->first;
                    iter->second = 0; //amount
            }
        }
    };
}