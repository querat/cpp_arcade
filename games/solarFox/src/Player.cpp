//
// Player.cpp for  in /home/querat_g/tmp/cpp_arcade/games/solarFox/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sat Apr  2 16:20:03 2016 querat_g
// Last update Sat Apr  2 20:06:31 2016 querat_g
//

#include "Player.hh"

Player::Player()
  : _x(MAP_WIDTH / 2)
  , _y(MAP_HEIGHT / 2)
  , _direction(Arcade::RIGHT)
{}

Player::~Player(){}

int
Player::getX() const
{
  return (this->_x);
}

int
Player::getY() const
{
  return (this->_y);
}

Arcade::Input
Player::getShootingDirection() const {
  return (_direction);
}

void
Player::setPosition(int x, int y)
{
  if (x >= MAP_WIDTH  || x < 0 ||
      y >= MAP_HEIGHT || y < 0 )
    return;
  this->_x = x;
  this->_y = y;
}

void
Player::drawInMap(Arcade::Tile *map) const
{
  map[(_y * MAP_WIDTH) + _x] = Arcade::PLAYER;
}

bool
Player::isDirection(Arcade::Input in)
{
  return (in == Arcade::UP   || in == Arcade::DOWN  ||
	  in == Arcade::LEFT || in == Arcade::RIGHT );
}

bool
Player::isSameAxis(Arcade::Input dir1, Arcade::Input dir2)
{
  return (((dir1 == Arcade::UP   || dir1 == Arcade::DOWN )  &&
	   (dir2 == Arcade::UP   || dir2 == Arcade::DOWN )) ||
	  ((dir1 == Arcade::LEFT || dir1 == Arcade::RIGHT)  &&
	   (dir2 == Arcade::LEFT || dir2 == Arcade::RIGHT)));
}

void
Player::changeDirection(Arcade::Input direction)
{
  if ((!isDirection(direction))) //  ||
      // (isSameAxis(direction, _direction)))
    return ;
  _direction = direction;
}

bool
Player::canMoveTo(Arcade::Tile const *map, int x, int y) const
{
  Arcade::Tile tile = map[(y * MAP_WIDTH) + x];

  if (x <= 1 || x >= (MAP_WIDTH  - 1) ||
      y <= 1 || y >= (MAP_HEIGHT - 1))
    return (false);
  return (tile == Arcade::EMPTY       ||
	  tile == Arcade::ENEMY_SHOT  ||
	  tile == Arcade::PLAYER_SHOT ||
	  tile == Arcade::ITEM        );
}

void
Player::move(Arcade::Tile const *map)
{
  switch (_direction)
    {

    case (Arcade::UP):
      if (canMoveTo(map, _x, (_y - 1)))
	--_y;
      break;

    case (Arcade::DOWN):
      if (canMoveTo(map, _x, (_y + 1)))
	++_y;
      break;

    case (Arcade::LEFT):
      if (canMoveTo(map, (_x - 1), (_y)))
	--_x;
      break;

    case (Arcade::RIGHT):
      if (canMoveTo(map, (_x + 1), (_y)))
	++_x;
      break;

    default: break;
    }
}
