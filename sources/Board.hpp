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
    public:
        int scientist_num_cards_discover_cure = 5;
        std::map<City, CityClass> citiesMap;
        std::map<City, std::set<City>> cities_connections;
        std::map<Color, bool> cures_found;
        int research_labs_num = 0;
        friend std::ostream &operator<<(std::ostream &outStream, Board &board);
        int &operator[](City city);
        bool is_clean();
        void remove_cures();
        void remove_stations();


        ///Board constructor:
        Board()
        {
            scientist_num_cards_discover_cure = 4;
            citiesMap = {
                {City::Algiers, CityClass("Algiers", Color::Black)},
                {City::Atlanta, CityClass("Atlanta", Color::Blue)},
                {City::Baghdad, CityClass("Baghdad", Color::Black)},
                {City::Bangkok, CityClass("Bangkok", Color::Red)},
                {City::Beijing, CityClass("Beijing", Color::Red)},
                {City::Bogota, CityClass("Bogota", Color::Yellow)},
                {City::BuenosAires, CityClass("BuenosAires", Color::Yellow)},
                {City::Cairo, CityClass("Cairo", Color::Black)},
                {City::Chennai, CityClass("Chennai", Color::Black)},
                {City::Chicago, CityClass("Chicago", Color::Blue)},
                {City::Delhi, CityClass("Delhi", Color::Black)},
                {City::Essen, CityClass("Essen", Color::Blue)},
                {City::HoChiMinhCity, CityClass("HoChiMinhCity", Color::Red)},
                {City::HongKong, CityClass("HongKong", Color::Red)},
                {City::Istanbul, CityClass("Istanbul", Color::Black)},
                {City::Jakarta, CityClass("Jakarta", Color::Red)},
                {City::Johannesburg, CityClass("Johannesburg", Color::Yellow)},
                {City::Karachi, CityClass("Karachi", Color::Black)},
                {City::Khartoum, CityClass("Khartoum", Color::Yellow)},
                {City::Kinshasa, CityClass("Kinshasa", Color::Yellow)},
                {City::Kolkata, CityClass("Kolkata", Color::Black)},
                {City::Lagos, CityClass("Lagos", Color::Yellow)},
                {City::Lima, CityClass("Lima", Color::Yellow)},
                {City::London, CityClass("London", Color::Blue)},
                {City::LosAngeles, CityClass("LosAngeles", Color::Yellow)},
                {City::Madrid, CityClass("Madrid", Color::Blue)},
                {City::Manila, CityClass("Manila", Color::Red)},
                {City::MexicoCity, CityClass("MexicoCity", Color::Yellow)},
                {City::Miami, CityClass("Miami", Color::Yellow)},
                {City::Milan, CityClass("Milan", Color::Blue)},
                {City::Montreal, CityClass("Montreal", Color::Blue)},
                {City::Moscow, CityClass("Moscow", Color::Black)},
                {City::Mumbai, CityClass("Mumbai", Color::Black)},
                {City::NewYork, CityClass("NewYork", Color::Blue)},
                {City::Osaka, CityClass("Osaka", Color::Red)},
                {City::Paris, CityClass("Paris", Color::Blue)},
                {City::Riyadh, CityClass("Riyadh", Color::Black)},
                {City::SanFrancisco, CityClass("SanFrancisco", Color::Blue)},
                {City::Santiago, CityClass("Santiago", Color::Yellow)},
                {City::SaoPaulo, CityClass("SaoPaulo", Color::Yellow)},
                {City::Seoul, CityClass("Seoul", Color::Red)},
                {City::Shanghai, CityClass("Shanghai", Color::Red)},
                {City::StPetersburg, CityClass("StPetersburg", Color::Blue)},
                {City::Sydney, CityClass("Sydney", Color::Red)},
                {City::Taipei, CityClass("Taipei", Color::Red)},
                {City::Tehran, CityClass("Tehran", Color::Black)},
                {City::Tokyo, CityClass("Tokyo", Color::Red)},
                {City::Washington, CityClass("Washington", Color::Blue)}};

            cities_connections = {
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
                {City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong}},
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

            cures_found = {
                {Color::Black, false}, {Color::Blue, false}, {Color::Yellow, false}, {Color::Red, false}};
        }
    };
};