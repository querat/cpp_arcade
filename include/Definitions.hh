//
// Definitions.hh for  in /home/querat_g/tmp/cpp_arcade
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Wed Mar 30 09:16:31 2016 querat_g
// Last update Sat Apr  2 19:46:50 2016 querat_g
//

#ifndef DEFINITIONS_HH_
# define DEFINITIONS_HH_

#include <stdint.h>
#include "Exceptions.hh"

# define MAP_WIDTH	30
# define MAP_HEIGHT	20

namespace	Arcade
{
  enum	Tile : uint16_t
    {
      EMPTY = 0,
      CLIP = 1,
      ENEMY = 3,
      ENEMY_SHOT = 4,
      PLAYER_SHOT = 5,
      ITEM = 6,
      PLAYER = 7,
    };

  enum	Color : uint16_t
    {
      BLACK,
	ORANGE,
	YELLOW,
	RED,
	PURPLE,
	BLUE,
	CYAN,
	GREEN
	};

  enum	Input : uint16_t
    {
      NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ONE,
	TWO,	// previous graphic lib
	THREE,	// next graphic lib
	FOUR,	// previous game
	FIVE,	// next game
	EIGHT,	// restart the game
	NINE,	// go back to menu
	ESC,	// echap == exit()
	SPACE,
	WHAT_THE_FUCK
    };
};

namespace	Arcade
{
  bool		canonMode();
  bool		rawMode();
  void		printKeyInput(Arcade::Input in);
  Input		reverseDirection(Input);
  bool		isSameAxis(Arcade::Input dir1, Arcade::Input dir2);
  bool		isDirection(Arcade::Input in);
};

#endif // !Definition.hh
