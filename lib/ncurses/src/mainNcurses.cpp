//
// mainNcurses.cpp for  in /home/querat_g/tmp/cpp_arcade/lib/ncurses
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Wed Mar 16 09:44:36 2016 querat_g
// Last update Sun Apr  3 14:24:24 2016 schmou_a
//

#include <iostream>
#include <termios.h>
#include <term.h>
#include "LibMyNcurses.hh"
#include "DlLoader.hh"

void
LibMyNcurses::test(void) const
{
  std::cerr << "libMyNcurses OK !" << std::endl;
}

LibMyNcurses::LibMyNcurses()
{
  char	*tname;
  struct termios term;

  initscr();
  start_color();
  _win = newwin(MAP_HEIGHT, MAP_WIDTH * 2, 0, 0);
  noecho();

  tname = getenv("TERM");
  tgetent(NULL, tname);
  tcgetattr(0, &term);

  term.c_cc[VMIN] = 0;
  term.c_cc[VTIME] = 0;

  tcsetattr(0, TCSADRAIN, &term);

  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_BLUE, COLOR_BLUE);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);
  init_pair(4, COLOR_CYAN, COLOR_CYAN);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);

  _colorMap.insert(std::make_pair(Arcade::RED, COLOR_PAIR(1)));
  _colorMap.insert(std::make_pair(Arcade::ORANGE, COLOR_PAIR(2)));
  _colorMap.insert(std::make_pair(Arcade::GREEN, COLOR_PAIR(3)));
  _colorMap.insert(std::make_pair(Arcade::CYAN, COLOR_PAIR(4)));
  _colorMap.insert(std::make_pair(Arcade::YELLOW, COLOR_PAIR(5)));

  _chr = 0;
  wrefresh(_win);

  this->_keyMap = t_stdinKeyMap
    ({
        std::make_pair(4283163, Arcade::UP   ),
	std::make_pair(4348699, Arcade::DOWN ),
	std::make_pair(4479771, Arcade::LEFT ),
	std::make_pair(4414235, Arcade::RIGHT),
	std::make_pair(49,      Arcade::ONE  ),
	std::make_pair(50,      Arcade::TWO  ),
	std::make_pair(51,      Arcade::THREE),
	std::make_pair(52,      Arcade::FOUR ),
	std::make_pair(53,      Arcade::FIVE ),
	std::make_pair(56,      Arcade::EIGHT),
	std::make_pair(57,      Arcade::NINE ),
	std::make_pair(38,      Arcade::ONE  ),
	std::make_pair(43459,   Arcade::TWO  ),
	std::make_pair(34,      Arcade::THREE),
	std::make_pair(39,      Arcade::FOUR ),
	std::make_pair(40,      Arcade::FIVE ),
	std::make_pair(95,      Arcade::EIGHT),
	std::make_pair(42947,   Arcade::NINE ),
        std::make_pair(27,      Arcade::ESC  ),
	std::make_pair(32,    Arcade::SPACE)
    });

}

LibMyNcurses::~LibMyNcurses()
{
  std::cerr << "destructing LibMyNcurses" << std::endl;

  struct termios term;

  tcgetattr(0, &term);

  term.c_lflag = (ICANON | ECHO);
  tcsetattr(0, 0, &term);

  werase(this->_win);
  delwin(this->_win);
  endwin();
}

void
LibMyNcurses::refresh()
{
  wrefresh(_win);
}

void
LibMyNcurses::destroyWindow()
{
  werase(this->_win);
  delwin(this->_win);
  endwin();
}

void
LibMyNcurses::clearWindow()
{
  werase(this->_win);
}

void
LibMyNcurses::drawSquare(size_t x, size_t y, Arcade::Color color)
{
  wattron(_win, _colorMap[color]);
  mvwprintw(_win, y, x * 2, "..");
  wattroff(_win, _colorMap[color]);
}

Arcade::Input
LibMyNcurses::pollEvents()
{
  int			buffer = 0;
  t_stdinKeyMapIt	it = this->_keyMap.begin();

  read(STDIN_FILENO, &buffer, sizeof(buffer));

  while (it != _keyMap.end())
    {
      if (buffer == it->first)
	return (it->second);
      ++it;
    }

  return (Arcade::NONE);
}

extern "C"
{
  IGraphicLib*
  loadLibrary()
  {
    return (new LibMyNcurses());
  }
}
