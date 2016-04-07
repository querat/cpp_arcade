//
// Enemy.hh for  in /home/querat_g/tmp/cpp_arcade/games/solarFox/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sat Apr  2 10:36:16 2016 querat_g
// Last update Sat Apr  2 15:35:29 2016 querat_g
//

#ifndef ENEMY_HH_
# define ENEMY_HH_

# include <list>
# include <iostream>
# include "SolarFox.hh"
# include "Definitions.hh"
# include "Projectile.hh"



class Enemy
{
public:
  Enemy(Arcade::Input where);
  ~Enemy();

private:
  Arcade::Input _where;
  Arcade::Input _direction;
  int		_x;
  int		_y;

private:

  void		reverseDirectionIfAtEdge();



public:
  void		move();
  void		drawInMap(Arcade::Tile *map) const;
  void		tryToShootEVIL_SHOOT(std::list<Projectile*> &list);
  Arcade::Input getShootingDirection() const;
};


#endif
