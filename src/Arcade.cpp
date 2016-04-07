//
// Arcade.cpp for  in /home/querat_g/tmp/cpp_arcade
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Wed Mar 30 09:43:57 2016 querat_g
// Last update Sun Apr  3 14:33:24 2016 querat_g
//

#include <termios.h>

#include <iostream>
#include <string>
#include "IGraphicLib.hh"

bool
Arcade::canonMode()
{
  struct termios        term;

  if (tcgetattr(0, &term) == -1)
    {
      std::cerr << "Arcade::canonMode(): tc_getattr failed" << std::endl;
      return (false);
    }
  term.c_lflag |= ICANON;
  term.c_lflag |= ECHO;
  if ((tcsetattr(0, TCSANOW, &term) == -1))
    {
      std:: cerr << "Arcade::canonMode(): tc_setattr failed" << std::endl;
      return (false);
    }
  return (true);
}

bool
Arcade::rawMode()
{
  struct termios        term;

  if (tcgetattr(0, &term) == -1)
    {
      std::cerr << "Arcade::rawMode(): tc_getattr failed" << std::endl;
      return (false);
    }
  term.c_lflag &= ~ICANON;
  term.c_lflag &= ~ECHO;
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSANOW, &term) == -1))
    {
      std::cerr << "Arcade::rawMode(): tcsetattr failed" << std::endl;
      return (false);
    }
  return (true);
}

Arcade::Input
Arcade::reverseDirection(Arcade::Input in)
{
  switch (in)
    {
    case (Arcade::UP):
      return (Arcade::DOWN);
      break;
    case (Arcade::DOWN):
      return (Arcade::UP);
      break;
    case (Arcade::LEFT):
      return (Arcade::RIGHT);
      break;
    case (Arcade::RIGHT):
      return (Arcade::LEFT);
      break;
    default:{}
    }
  return (Arcade::NONE);
}

bool
Arcade::isDirection(Arcade::Input in)
{
  return (in == Arcade::UP   || in == Arcade::DOWN ||
	  in == Arcade::LEFT || in == Arcade::LEFT );
}

bool
Arcade::isSameAxis(Arcade::Input dir1, Arcade::Input dir2)
{
  return (((dir1 == Arcade::UP   || dir1 == Arcade::DOWN )  &&
	   (dir2 == Arcade::UP   || dir2 == Arcade::DOWN )) ||
	  ((dir1 == Arcade::LEFT || dir1 == Arcade::RIGHT)  &&
	   (dir2 == Arcade::LEFT || dir2 == Arcade::RIGHT)));
}

void
Arcade::printKeyInput(Arcade::Input in)
{
  static std::string tab[] =
    {
      "NONE",
      "UP",
      "DOWN",
      "LEFT",
      "RIGHT",
      "ONE",
      "TWO",	// previous graphic lib
      "THREE",	// next graphic lib
      "FOUR",	// previous game
      "FIVE",	// next game
      "EIGHT",	// restart the game
      "NINE",	// go back to menu
      "ESC",	// echap == exit()
      "WHAT_THE_FUCK"
    };

  std::cerr << tab[in];
}
