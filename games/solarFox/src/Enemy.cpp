//
// Enemy.cpp for  in /home/querat_g/tmp/cpp_arcade/games/solarFox/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sat Apr  2 10:38:31 2016 querat_g
// Last update Sat Apr  2 17:16:11 2016 querat_g
//

#include <iostream>
 #include "SolarFox.hh"

 Enemy::Enemy(Arcade::Input where)
   : _where(where)
   , _direction(Arcade::LEFT)
   , _x(0)
   , _y(0)
 {
   switch (where)
     {

     case (Arcade::UP): // top enemy starts at upper left
       _direction = Arcade::RIGHT;
       _x = 1;
       _y = 0;
       break;

     case (Arcade::DOWN): // bottom enemy starts at lower right
       _direction = Arcade::LEFT;
       _x = (MAP_WIDTH  - 2);
       _y = (MAP_HEIGHT - 1);
       break;

     case (Arcade::LEFT): // Left enemy starts at lower left
       _direction = Arcade::UP;
       _x = (0);
       _y = (MAP_HEIGHT - 2);
       break;

     case (Arcade::RIGHT): // Right enemy starts at upper right
       _direction = Arcade::DOWN;
       _x = (MAP_WIDTH  - 1);
       _y = (1);
       break;

     default:
       std::cerr << "Enemy::Enemy(): invalid enemy position" << std::endl;
       throw std::exception();
       break;

     }
 }

 Enemy::~Enemy(){}

 void
 Enemy::reverseDirectionIfAtEdge()
 {
   if (_direction == Arcade::LEFT && this->_x == 2)
     _direction = Arcade::RIGHT;
   else if (_direction == Arcade::RIGHT && this->_x == (MAP_WIDTH - 3))
     _direction = Arcade::LEFT;
   if (_direction == Arcade::UP && this->_y == 2)
     _direction = Arcade::DOWN;
   else if (_direction == Arcade::DOWN && this->_y == (MAP_HEIGHT - 3))
     _direction = Arcade::UP;
 }

 void
 Enemy::move()
 {
   this->reverseDirectionIfAtEdge();

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
Enemy::drawInMap(Arcade::Tile *map) const
{
  map[(this->_y * MAP_WIDTH) + this->_x] = Arcade::Tile::ENEMY;
}

Arcade::Input
Enemy::getShootingDirection() const
{
  Arcade::Input pewPew;

  switch (_where) {
  case (Arcade::LEFT ): pewPew = Arcade::RIGHT; break;
  case (Arcade::RIGHT): pewPew = Arcade::LEFT ; break;
  case (Arcade::UP   ): pewPew = Arcade::DOWN ; break;
  case (Arcade::DOWN ): pewPew = Arcade::UP   ; break;
  default             : pewPew = Arcade::NONE ; break;
  }

  return (pewPew);
}

void
Enemy::tryToShootEVIL_SHOOT(t_ProjectileList &list)
{
  bool	boule = rand() % SOLARFOX_EVIL_SHOOT_CHANCE;

  if (!boule)
    list.push_back(new Projectile(_x, _y, getShootingDirection()));

}
