//
// Merdinette.cpp for  in /home/querat_g/tmp/cpp_arcade/games/solarFox/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sat Apr  2 17:22:56 2016 querat_g
// Last update Sat Apr  2 20:17:43 2016 schmou_a
//

#include <unistd.h>

#include "SolarFox.hh"
#include "Protocol.hpp"

void    SolarFox::writeMap()
{
  int   size;
  struct arcade::GetMap *map;

  size =
    sizeof(struct arcade::GetMap) +
    (sizeof(arcade::TileType) * (MAP_WIDTH * MAP_HEIGHT));

  map = (struct arcade::GetMap *)calloc(1, size);

  map->type = arcade::CommandType::GET_MAP;
  map->width = MAP_WIDTH;
  map->height = MAP_HEIGHT;
  for (int y = 0; y < (MAP_HEIGHT); y++)
    {
      for (int x = 0; x < (MAP_WIDTH); x++)
        {
          map->tile[(y * MAP_WIDTH) + x] = (arcade::TileType)getTileAtPos(x, y);
	}
    }
  write(1, map, size);
}

void	SolarFox::whereAmI() const
{
  int                           size =
    sizeof(struct arcade::WhereAmI) +
    (sizeof(struct arcade::Position));

  struct arcade::WhereAmI       *w = (struct arcade::WhereAmI*)calloc(1, size);

  w->type = arcade::CommandType::WHERE_AM_I;
  w->lenght = 1;

  w->position->x = _player.getX();
  w->position->y = _player.getY();
  write(1, w, size);
}

extern "C"
{
  void		Play()
  {
    SolarFox	fox;
    uint16_t	cmd;

    cmd = 0;
    while (read(0, &cmd, sizeof(uint16_t)))
      {
   	switch (cmd)
   	  {
   	  case (static_cast<uint16_t>(arcade::CommandType::GET_MAP)):
   	    fox.writeMap();
   	    std::cerr << "get map" << std::endl;
   	    break;
   	  case (static_cast<uint16_t>(arcade::CommandType::WHERE_AM_I)):
   	    fox.whereAmI();
   	    std::cerr << "where am I" << std::endl;
   	    break;
   	  case (static_cast<uint16_t>(arcade::CommandType::GO_UP)):
   	    fox.sendInput(Arcade::Input::UP);
   	    std::cerr << "up" << std::endl;
   	    break;
   	  case (static_cast<uint16_t>(arcade::CommandType::SHOOT)):
   	    fox.sendInput(Arcade::Input::SPACE);
   	    std::cerr << "I SHOOT THE EVIL DUDES OLOLOL" << std::endl;
   	    break;
   	  case (static_cast<uint16_t>(arcade::CommandType::GO_DOWN)):
   	    fox.sendInput(Arcade::Input::DOWN);
   	    std::cerr << "down" << std::endl;
   	    break;
   	  case (static_cast<uint16_t>(arcade::CommandType::GO_LEFT)):
   	    fox.sendInput(Arcade::Input::LEFT);
   	    std::cerr << "left" << std::endl;
   	    break;
   	  case (static_cast<uint16_t>(arcade::CommandType::GO_RIGHT)):
   	    std::cerr << "right" << std::endl;
   	    fox.sendInput(Arcade::Input::RIGHT);
   	    break;
   	  case (static_cast<uint16_t>(arcade::CommandType::PLAY)):
   	    std::cerr << "play" << std::endl;
   	    fox.tick();
   	    break;
   	  }
     	cmd = 0;
      }
  }
}
