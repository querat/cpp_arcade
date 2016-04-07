//
// SolarFox.cpp for  in /home/querat_g/tmp/cpp_arcade/games/solarFox
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 19:52:42 2016 querat_g
// Last update Sat Apr  2 18:41:52 2016 schmou_a
//

#include <cstdlib>

#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Protocol.hpp"
#include "Snake.hh"
#include "IGame.hh"

Snake::Snake() : _direction(Arcade::DOWN)
{
  srandom(time(NULL));
  this->startGame();
}

Snake::~Snake()
{
}

void
Snake::startGame()
{
  this->restartGame();
}

void
Snake::exitGame()
{
}

void
Snake::restartGame()
{
  _direction = Arcade::DOWN;
  _blocks.clear();

  _blocks.push_front(std::make_pair(MAP_WIDTH / 2, MAP_HEIGHT / 2 - 3));
  _blocks.push_front(std::make_pair(MAP_WIDTH / 2, MAP_HEIGHT / 2 - 2));
  _blocks.push_front(std::make_pair(MAP_WIDTH / 2, MAP_HEIGHT / 2 - 1));
  _blocks.push_front(std::make_pair(MAP_WIDTH / 2, MAP_HEIGHT / 2));

  randomizeFoodPosition();

  fillMap();
}

bool
Snake::sameAxis(Arcade::Input direction) const
{
  return (((_direction == Arcade::UP   || _direction == Arcade::DOWN )  &&
	   ( direction == Arcade::UP   ||  direction == Arcade::DOWN )) ||
	  ((_direction == Arcade::LEFT || _direction == Arcade::RIGHT)  &&
	   ( direction == Arcade::LEFT ||  direction == Arcade::RIGHT)));
}

void
Snake::sendInput(Arcade::Input direction)
{

  // on n'accepte que les touches directionelles
  if (direction != Arcade::UP   && direction != Arcade::DOWN &&
      direction != Arcade::LEFT && direction != Arcade::RIGHT)
    return;

  // Prévention suicide
  if (sameAxis(direction))
    return ;

  _direction = direction;
}

void
Snake::tick()
{

  bool	isAlive = this->move();

  if (!isAlive)
    this->restartGame();

  // remplissage de la map pour la merdinette
  // et la lib graphique
  fillMap();
  usleep(50000);



}

void
Snake::randomizeFoodPosition()
{
  bool	ok = false;
  int	x;
  int	y;

  while (!ok)
    {
      x = random() % MAP_WIDTH;
      y = random() % MAP_HEIGHT;
      if (getTileAtPos(x, y) == Arcade::EMPTY)
	{
	  ok = true;
	  _foodPos.first = x;
	  _foodPos.second = y;
	  _map[(y * MAP_WIDTH) + x] = Arcade::ITEM;
	}
    }
}

void
Snake::drawInMap()
{
}

bool
Snake::isEatingFood() const
{
  return((_blocks.begin()->first  == _foodPos.first ) &&
	 (_blocks.begin()->second == _foodPos.second) );
}

bool
Snake::isEatingSelf() const
{
  Blocks::const_iterator	i = _blocks.begin();
  int	x = i->first;
  int	y = i->second;
  ++i;
  while (i != _blocks.end())
    {
      if (i->first == x && i->second == y)
	{
	  std::cerr << "DED" << std::endl;
	  return (true);
	}
      ++i;
    }
  return (false);
}

bool
Snake::move()
{
  switch (_direction)
    {
    case (Arcade::UP):
      _blocks.push_front(std::make_pair(_blocks.begin()->first, _blocks.begin()->second - 1));
      break;
    case (Arcade::DOWN):
      _blocks.push_front(std::make_pair(_blocks.begin()->first, _blocks.begin()->second + 1));
      break;
    case (Arcade::LEFT):
      _blocks.push_front(std::make_pair(_blocks.begin()->first - 1, _blocks.begin()->second));
      break;
    case (Arcade::RIGHT):
      _blocks.push_front(std::make_pair(_blocks.begin()->first + 1, _blocks.begin()->second));
      break;
    default:{}
    }

  if ((_blocks.begin()->first  < 0 || _blocks.begin()->first  >= MAP_WIDTH ) ||
      (_blocks.begin()->second < 0 || _blocks.begin()->second >= MAP_HEIGHT) ||
      (isEatingSelf()))
    return (false);

  if (!isEatingFood())
    _blocks.pop_back();
  else
    randomizeFoodPosition();

  return (true);
}

void
Snake::fillMap()
{
  for (int y = 0; y < MAP_HEIGHT; y++)
    {
      for (int x = 0; x < MAP_WIDTH; x++)
	{
	  _map[(y * MAP_WIDTH) + x] = this->getTileAtPos(x, y);
	}
    }
}

Arcade::Tile
Snake::getTileAtPos(int x, int y) const
{
  if (_foodPos.first == x && _foodPos.second == y)
    return (Arcade::ITEM);

  for (Blocks::const_iterator i = _blocks.begin(); i != _blocks.end(); ++i)
    {
      if (i->first == x && i->second == y)
	return (Arcade::PLAYER);
    }
  return (Arcade::EMPTY);
}

Arcade::Tile const *
Snake::getMap() const
{
  return (_map);
}

void	Snake::writeMap()
{
  int	size;
  struct arcade::GetMap	*map;

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

void	Snake::whereAmI() const
{
  int				nbSnek = _blocks.size();
  int				size =
    sizeof(struct arcade::WhereAmI) +
    (nbSnek * sizeof(struct arcade::Position));

  struct arcade::WhereAmI	*w = (struct arcade::WhereAmI*)calloc(1, size);

  w->type = arcade::CommandType::WHERE_AM_I;
  w->lenght = nbSnek;

  int			 i = 0;
  Blocks::const_iterator it = _blocks.begin();

  while	(it != _blocks.end())
    {
      w->position[i].x = it->first;
      w->position[i].y = it->second;
      ++i;
      ++it;
    }
  write(1, w, size);


}

extern "C"
{
  IGame		*loadGame()
  {
    return (new Snake);
  }

  void		Play()
  {
    Snake	snek;
    uint16_t	cmd;

    cmd = 0;

    while (read(0, &cmd, sizeof(uint16_t)))
      {

	switch (cmd)
	  {
	  case (static_cast<uint16_t>(arcade::CommandType::GET_MAP)):
	    snek.writeMap();
	    std::cerr << "get map" << std::endl;
	    break;
	  case (static_cast<uint16_t>(arcade::CommandType::WHERE_AM_I)):
	    snek.whereAmI();
	    std::cerr << "where am I" << std::endl;
	    break;
	  case (static_cast<uint16_t>(arcade::CommandType::GO_UP)):
	    snek.sendInput(Arcade::Input::UP);
	    std::cerr << "up" << std::endl;
	    break;
	  case (static_cast<uint16_t>(arcade::CommandType::GO_DOWN)):
	    snek.sendInput(Arcade::Input::DOWN);
	    std::cerr << "down" << std::endl;
	    break;
	  case (static_cast<uint16_t>(arcade::CommandType::GO_LEFT)):
	    snek.sendInput(Arcade::Input::LEFT);
	    std::cerr << "left" << std::endl;
	    break;
	  case (static_cast<uint16_t>(arcade::CommandType::GO_RIGHT)):
	    std::cerr << "right" << std::endl;
	    snek.sendInput(Arcade::Input::RIGHT);
	    break;
	  case (static_cast<uint16_t>(arcade::CommandType::PLAY)):
	    std::cerr << "play" << std::endl;
	    snek.tick();
	    break;
	  }
    	cmd = 0;
      }


  }
}
