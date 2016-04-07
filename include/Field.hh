//
// Created by lina_a on 30/03/16.
//

#ifndef SNAKE_FIELD_HH
#define SNAKE_FIELD_HH

#include <vector>
#include "IGame.hh"
#include "Protocol.hpp"
#include "IGraphicLib.hh"

class Field
{
public:
  Field();
  void			setBlock(Arcade::Tile tile, int, int);
  void			newFruit();
  Arcade::Tile		getBlock(int, int) const;
  Arcade::Tile const	*getMap() const ;

private:
  Arcade::Tile   map[MAP_WIDTH * MAP_HEIGHT];
};

#endif //SNAKE_FIELD_HH
