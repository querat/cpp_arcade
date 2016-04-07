//
// Snake.hh for  in /home/querat_g/tmp/cpp_arcade/games/solarFox
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 19:52:44 2016 querat_g
// Last update Fri Apr  1 17:18:07 2016 querat_g
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

#include <list>
# include "IGame.hh"
# include "IGraphicLib.hh"
# include "Definitions.hh"

class	Snake : public IGame
{
public:

  Snake();
  ~Snake();
  void				startGame();
  void				exitGame();
  void				restartGame();
  void				sendInput(Arcade::Input);
  void				tick();
  Arcade::Tile const *		getMap() const;
  void				writeMap();
  void				drawMap();
  void				whereAmI() const;

private:
  bool				isEatingSelf() const;
  bool				directionIsSameAxis(Arcade::Input) const;
  void				changeDirection();
  void				randomizeFoodPosition();
  void				fillMap();
  Arcade::Tile			getTileAtPos(int x, int y) const;
  void				drawInMap();
  bool				move();
  bool				isEatingFood() const;
  bool				sameAxis(Arcade::Input direction) const;

private:

  typedef std::list<std::pair<int, int>>	Blocks;
  Blocks					_blocks;
  Arcade::Input					_direction;
  Arcade::Tile					_map[MAP_WIDTH * MAP_HEIGHT];
  std::pair<int, int>				_foodPos;


};

#endif // !Snake.hh
