//
// Player.hh for  in /home/querat_g/tmp/cpp_arcade/games/solarFox/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sat Apr  2 16:16:14 2016 querat_g
// Last update Sat Apr  2 19:26:41 2016 querat_g
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <list>
# include "Definitions.hh"

class Player
{
public:
  Player();
  ~Player();

private:
  int		_x;
  int		_y;
  Arcade::Input	_direction;

private:
  bool		isSameAxis(Arcade::Input dir1, Arcade::Input dir2);
  bool		isDirection(Arcade::Input dir);
  bool		canMoveTo(Arcade::Tile const *map, int x, int y) const;

public:
  void		changeDirection(Arcade::Input dir);
  void		move(Arcade::Tile const *map);
  void		setPosition(int x, int y);
  void		drawInMap(Arcade::Tile *map) const;
  int		getX() const;
  int		getY() const;
  Arcade::Input	getShootingDirection() const;



};


#endif
