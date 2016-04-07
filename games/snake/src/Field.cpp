//
// Field.cpp for  in /home/schmou/cpp/cpp_arcade/games/snake/src
//
// Made by schmou_a
// Login   <schmou@epitech.net>
//
// Started on  Wed Mar 30 17:49:43 2016 schmou_a
// Last update Thu Mar 31 14:31:39 2016 querat_g
//

#include <iostream>
#include "Field.hh"
#include "Protocol.hpp"

Field::Field()
{
    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        for (int j = 0; j < MAP_WIDTH; ++j)
        {
	        map[(i * MAP_WIDTH) + j] = Arcade::Tile::EMPTY;
        }
    }
    newFruit();
}

void Field::setBlock(Arcade::Tile tile, int x, int y)
{
    map[x + (y * MAP_WIDTH)] = tile;
}

Arcade::Tile Field::getBlock(int x, int y) const
{
    return map[x + (y * MAP_WIDTH)];
}

void Field::newFruit()
{
    int     x;
    int     y;

    do
    {
        x = rand() % MAP_WIDTH;
        y = rand() % MAP_HEIGHT;
    }
    while ((getBlock(x, y)) != Arcade::EMPTY);
    setBlock(Arcade::ITEM, x, y);
}

Arcade::Tile const *Field::getMap() const
{
    std::cout << map << std::endl;
    return map;
}
