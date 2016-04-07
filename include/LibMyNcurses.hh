//
// LibMyNcurses.hh for  in /home/querat_g/tmp/cpp_arcade/lib/SFML/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 12:37:39 2016 querat_g
// Last update Sun Apr  3 13:48:44 2016 querat_g
//

#ifndef LIBMYNCURSES_HH_
# define LIBMYNCURSES_HH_

#include <curses.h>
#include <unistd.h>
#include <vector>
#include <utility>
#include <map>
#include "Protocol.hpp"
#include "IGraphicLib.hh"

typedef std::map<Arcade::Color, int> t_colorMap;
typedef std::vector<std::pair<int, Arcade::Input>>	t_stdinKeyMap;
typedef t_stdinKeyMap::iterator				t_stdinKeyMapIt;

class	LibMyNcurses : public IGraphicLib
{

private:

  WINDOW	*_win;
  int		_chr;
  t_colorMap	_colorMap;
  t_stdinKeyMap	_keyMap;

public:
  LibMyNcurses();
  ~LibMyNcurses();

  void			test(void) const;
  void			refresh();
  void			destroyWindow();
  void			clearWindow();
  void			drawSquare(size_t x, size_t y, Arcade::Color color);
  Arcade::Input		pollEvents();};

#endif
