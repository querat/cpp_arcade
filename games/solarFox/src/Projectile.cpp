//
// Projectile.cpp for  in /home/querat_g/tmp/cpp_arcade/games/solarFox/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sat Apr  2 12:55:53 2016 querat_g
// Last update Sat Apr  2 19:57:54 2016 querat_g
//

#include <iostream>
#include "SolarFox.hh"

Projectile::Projectile(int x, int y, Arcade::Input direction)
  : _x(x)
  , _y(y)
  , _direction(direction)
  , _team(Projectile::ENEMY)
{}

Projectile::Projectile(int x, int y, Arcade::Input direction,
		       Projectile::Team team)
  : _x(x)
  , _y(y)
  , _direction(direction)
  , _team(team)
{}

Projectile::~Projectile(){}

bool
Projectile::reachedEdge() const
{
  return (_x >= MAP_WIDTH || _y >= MAP_HEIGHT ||
	  _x < 0          || _y < 0            );
}

bool
Projectile::hitPlayer(Player const & player)
{
  return (this->_x == player.getX() &&
	  this->_y == player.getY() &&
	  this->_team != Projectile::PLAYER);
}

void
Projectile::move()
{
  switch (_direction)
    {
    case (Arcade::UP):
      --_y;
      break;

    case (Arcade::DOWN):
      ++_y;
      break;

    case (Arcade::LEFT):
      --_x;
      break;

    case (Arcade::RIGHT):
      ++_x;
      break;

    default:
      std::cerr << "Invalid direction" << std::endl;
      break;
    }
}

void
Projectile::drawInMap(Arcade::Tile *map) const {
  if (_team == Projectile::ENEMY)
    map[(this->_y * MAP_WIDTH) + this->_x] = Arcade::ENEMY_SHOT;
  else
    map[(this->_y * MAP_WIDTH) + this->_x] = Arcade::PLAYER_SHOT;
}
