#pragma once
#include <string>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include "City.hpp"
#include "Color.hpp"
#include "CityClass.hpp"
#include <set>

using namespace pandemic;

namespace pandemic
{
    class Board
    {
    private:
    public:
        int scientist_num_cards_discover_cure = 5;

        Board(int n)
        {
            scientist_num_cards_discover_cure = n;
        }

        Board()
        {
            scientist_num_cards_discover_cure = 4;
        }
        std::map<City, CityClass> citiesMap{
            {City::Algiers, CityClass(City::Algiers, Color::Black)},
            {City::Atlanta, CityClass(City::Atlanta, Color::Blue)},
            {City::Baghdad, CityClass(City::Baghdad, Color::Black)},
            {City::Bangkok, CityClass(City::Bangkok, Color::Red)},
            {City::Beijing, CityClass(City::Beijing, Color::Red)},
            {City::Bogota, CityClass(City::Bogota, Color::Yellow)},
            {City::BuenosAires, CityClass(City::BuenosAires, Color::Yellow)},
            {City::Cairo, CityClass(City::Cairo, Color::Black)},
            {City::Chennai, CityClass(City::Chennai, Color::Black)},
            {City::Chicago, CityClass(City::Chicago, Color::Blue)},
            {City::Delhi, CityClass(City::Delhi, Color::Black)},
            {City::Essen, CityClass(City::Essen, Color::Blue)},
            {City::HoChiMinhCity, CityClass(City::HoChiMinhCity, Color::Red)},
            {City::HongKong, CityClass(City::HongKong, Color::Red)},
            {City::Istanbul, CityClass(City::Istanbul, Color::Black)},
            {City::Jakarta, CityClass(City::Jakarta, Color::Red)},
            {City::Johannesburg, CityClass(City::Johannesburg, Color::Yellow)},
            {City::Karachi, CityClass(City::Karachi, Color::Black)},
            {City::Khartoum, CityClass(City::Khartoum, Color::Yellow)},
            {City::Kinshasa, CityClass(City::Kinshasa, Color::Yellow)},
            {City::Kolkata, CityClass(City::Kolkata, Color::Black)},
            {City::Lagos, CityClass(City::Lagos, Color::Yellow)},
            {City::Lima, CityClass(City::Lima, Color::Yellow)},
            {City::London, CityClass(City::London, Color::Blue)},
            {City::LosAngeles, CityClass(City::LosAngeles, Color::Yellow)},
            {City::Madrid, CityClass(City::Madrid, Color::Blue)},
            {City::Manila, CityClass(City::Manila, Color::Red)},
            {City::MexicoCity, CityClass(City::MexicoCity, Color::Yellow)},
            {City::Miami, CityClass(City::Miami, Color::Yellow)},
            {City::Milan, CityClass(City::Milan, Color::Blue)},
            {City::Montreal, CityClass(City::Montreal, Color::Blue)},
            {City::Moscow, CityClass(City::Moscow, Color::Black)},
            {City::Mumbai, CityClass(City::Mumbai, Color::Black)},
            {City::NewYork, CityClass(City::NewYork, Color::Blue)},
            {City::Osaka, CityClass(City::Osaka, Color::Red)},
            {City::Paris, CityClass(City::Paris, Color::Blue)},
            {City::Riyadh, CityClass(City::Riyadh, Color::Black)},
            {City::SanFrancisco, CityClass(City::SanFrancisco, Color::Blue)},
            {City::Santiago, CityClass(City::Santiago, Color::Yellow)},
            {City::SaoPaulo, CityClass(City::SaoPaulo, Color::Yellow)},
            {City::Seoul, CityClass(City::Seoul, Color::Red)},
            {City::Shanghai, CityClass(City::Shanghai, Color::Red)},
            {City::StPetersburg, CityClass(City::StPetersburg, Color::Blue)},
            {City::Sydney, CityClass(City::Sydney, Color::Red)},
            {City::Taipei, CityClass(City::Taipei, Color::Red)},
            {City::Tehran, CityClass(City::Tehran, Color::Black)},
            {City::Tokyo, CityClass(City::Tokyo, Color::Red)},
            {City::Washington, CityClass(City::Washington, Color::Blue)}};

        std::map<City, std::set<City>> cities_connections{
            {City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo}},
            {City::Atlanta, {City::Chicago, City::Miami, City::Washington}},
            {City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}},
            {City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}},
            {City::Beijing, {City::Shanghai, City::Seoul}},
            {City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}},
            {City::BuenosAires, {City::Bogota, City::SaoPaulo}},
            {City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}},
            {City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}},
            {City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}},
            {City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}},
            {City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg}},
            {City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila}},
            {City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}},
            {City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}},
            {City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}},
            {City::Johannesburg, {City::Kinshasa, City::Khartoum}},
            {City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}},
            {City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}},
            {City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg}},
            {City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong}},
            {City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa}},
            {City::Lima, {City::MexicoCity, City::Bogota, City::Santiago}},
            {City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris}},
            {City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}},
            {City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}},
            {City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}},
            {City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}},
            {City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}},
            {City::Milan, {City::Essen, City::Paris, City::Istanbul}},
            {City::Montreal, {City::Chicago, City::Washington, City::NewYork}},
            {City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran}},
            {City::Mumbai, {City::Karachi, City::Delhi, City::Chennai}},
            {City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid}},
            {City::Osaka, {City::Taipei, City::Tokyo}},
            {City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}},
            {City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi}},
            {City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}},
            {City::Santiago, {City::Lima}},
            {City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}},
            {City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo}},
            {City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}},
            {City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow}},
            {City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles}},
            {City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila}},
            {City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi}},
            {City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}},
            {City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami}}};

        std::map<Color, bool> cures_found{
            {Color::Black, false}, {Color::Blue, false},  {Color::Yellow, false},  {Color::Red, false}
        };

        int research_labs_num = 0;
        friend std::ostream &operator<<(std::ostream &outStream, Board &board);
        int &operator[](City city);
        bool is_clean()
        {
            std::map<City, CityClass>::iterator iter = citiesMap.begin();
            std::map<City, CityClass>::iterator endIter = citiesMap.end();
            for (; iter != endIter; ++iter)
            {
                CityClass city = iter->second;
                if (city.diseaseLevel != 0)
                {
                    return false;
                }
            }
            return true;
        }

        void remove_cures()
        {
            std::map<Color, bool>::iterator iter = cures_found.begin();
            std::map<Color, bool>::iterator endIter = cures_found.end();
            for (; iter != endIter; ++iter)
            {
                iter->second= false;
            }
        };

        void remove_stations(){
            std::map<City, CityClass>::iterator iter = citiesMap.begin();
            std::map<City, CityClass>::iterator endIter = citiesMap.end();
            for (; iter != endIter; ++iter)
            {
                iter->second.research_lab_exist= false;
            }
        }
    };

}