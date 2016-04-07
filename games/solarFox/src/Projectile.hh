//
// Projectile.hh for  in /home/querat_g/tmp/cpp_arcade/games/solarFox/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sat Apr  2 12:52:04 2016 querat_g
// Last update Sat Apr  2 19:29:36 2016 querat_g
//

#ifndef PROJECTILE_HH_
# define PROJECTILE_HH_

# include <map>
# include <utility>
# include "Definitions.hh"
# include "Player.hh"

class Projectile
{
public:
  enum		Team
    {
      PLAYER,
      ENEMY
    };

public:
  Projectile(int x, int y, Arcade::Input direction);
  Projectile(int x, int y, Arcade::Input direction, Team team);
  ~Projectile();

private:
  int		_x;
  int		_y;
  Arcade::Input	_direction;
  Team		_team;

private:

public:
  void		move();
  void		drawInMap(Arcade::Tile *map) const;
  bool		reachedEdge(void) const;
  bool		hitPlayer(Player const & player);

};

#endif
