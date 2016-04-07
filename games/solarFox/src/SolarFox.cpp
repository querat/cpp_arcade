//
// SolarFox.cpp for  in /home/querat_g/tmp/cpp_arcade/games/solarFox
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 19:52:42 2016 querat_g
// Last update Sat Apr  2 20:27:17 2016 querat_g
//

#include <cstdlib>
#include <unistd.h>

#include <iostream>
#include "SolarFox.hh"
#include "Definitions.hh"

SolarFox::SolarFox()

{
  srand(time(NULL));
  this->startGame();
}

SolarFox::~SolarFox()
{
}

arcade::TileType
SolarFox::getTileAtPos(int x, int y)
{
  return (static_cast<arcade::TileType>(_map[(y * MAP_WIDTH) + x]));
}

void
SolarFox::startGame()
{
  this->restartGame();
}

void
SolarFox::exitGame()
{
}

void
SolarFox::drawProjectiles()
{
  t_ProjectileList::const_iterator it = _projectiles.begin();

  while (it != _projectiles.end())
    {
      (*it)->drawInMap(_map);
      ++it;
    }

}

void
SolarFox::reDrawMap()
{
  this->clearMap();
  this->reDrawClipWall();
  this->drawEnemies();
  this->drawProjectiles();
  this->_player.drawInMap(_map);
}

void
SolarFox::drawEnemies()
{
  t_enemyMap::iterator it = _enemies.begin();

  while (it != _enemies.end())
    {
      it->second.drawInMap(_map);
      ++it;
    }
}

//
// Fills the map with Arcade::Tile::EMPTY
//
void
SolarFox::clearMap()
{
  for (int y = 0; y < MAP_HEIGHT; y++)
    for (int x = 0; x < MAP_WIDTH; x++)
      _map[(y * MAP_WIDTH) + x] = Arcade::Tile::EMPTY;
}

//
// Redraws the invisible walls that makes it impossible for the
// player to reach the enemies
//
void
SolarFox::reDrawClipWall()
{
  for (int x = 1; x < (MAP_WIDTH - 1); x++)
    {
      _map[(1                * MAP_WIDTH) + x] = Arcade::CLIP;
      _map[((MAP_HEIGHT - 2) * MAP_WIDTH) + x] = Arcade::CLIP;
    }
  for (int y = 1; y < (MAP_HEIGHT - 1); y++)
    {
      _map[(y * MAP_WIDTH) + (1            )] = Arcade::CLIP;
      _map[(y * MAP_WIDTH) + (MAP_WIDTH - 2)] = Arcade::CLIP;
    }
}

void
SolarFox::createEnemies()
{
  this->_enemies = t_enemyMap({
        std::make_pair(Arcade::UP   , Enemy(Arcade::UP   )),
	std::make_pair(Arcade::DOWN , Enemy(Arcade::DOWN )),
	std::make_pair(Arcade::LEFT , Enemy(Arcade::LEFT )),
	std::make_pair(Arcade::RIGHT, Enemy(Arcade::RIGHT))
    });
}

void
SolarFox::deleteProjectiles(){
  _projectiles.clear();
}

void
SolarFox::restartGame()
{
  this->_player.setPosition((MAP_WIDTH / 2), (MAP_HEIGHT / 2));
  this->createEnemies();
  this->reDrawMap();
  this->deleteProjectiles();
}

void
SolarFox::sendInput(Arcade::Input in)
{
  _player.changeDirection(in);
  if (in == Arcade::Input::SPACE)
    {
      Projectile *pewPew = new Projectile(_player.getX(),
					  _player.getY(),
					  _player.getShootingDirection(),
					  Projectile::PLAYER);
      pewPew->move();
      _projectiles.push_back(pewPew);
      std::cerr << "MY_SHOOT" << std::endl;
    }
  reDrawMap();
}

void
SolarFox::tick()
{
  // déplacement du joueur
  _player.move(_map);

  // update des ennemis
  t_enemyMap::iterator i = _enemies.begin();
  while (i != _enemies.end())
    {
      i->second.move();
      i->second.tryToShootEVIL_SHOOT(this->_projectiles);
      ++i;
    }

  // update des projectiles
  t_ProjectileList::iterator it = _projectiles.begin();
  while (it != _projectiles.end())
    {
      (*it)->move();
      if ((*it)->hitPlayer(this->_player))
	{
	  this->restartGame();
	  break;
	}
      if ((*it)->reachedEdge())
	{
	  delete (*it);
	  it = _projectiles.erase(it);
	}
      else
	++it;
    }

  reDrawMap();
  usleep(SOLARFOX_USLEEP);
}

Arcade::Tile const *
SolarFox::getMap() const
{
  return (this->_map);
}

extern "C"
{
  IGame		*loadGame()
  {
    return (new SolarFox);
  }

  // void		Play()
  // {
  //   SolarFox	fox;
  //   uint16_t	cmd;

  //   cmd = 0;
  //   while (read(0, &cmd, sizeof(uint16_t)))
  //     {
  // 	switch (cmd)
  // 	  {
  // 	  case (static_cast<uint16_t>(arcade::CommandType::GET_MAP)):
  // 	    fox.writeMap();
  // 	    std::cerr << "get map" << std::endl;
  // 	    break;
  // 	  case (static_cast<uint16_t>(arcade::CommandType::WHERE_AM_I)):
  // 	    fox.whereAmI();
  // 	    std::cerr << "where am I" << std::endl;
  // 	    break;
  // 	  case (static_cast<uint16_t>(arcade::CommandType::GO_UP)):
  // 	    fox.sendInput(Arcade::Input::UP);
  // 	    std::cerr << "up" << std::endl;
  // 	    break;
  // 	  case (static_cast<uint16_t>(arcade::CommandType::GO_DOWN)):
  // 	    fox.sendInput(Arcade::Input::DOWN);
  // 	    std::cerr << "down" << std::endl;
  // 	    break;
  // 	  case (static_cast<uint16_t>(arcade::CommandType::GO_LEFT)):
  // 	    fox.sendInput(Arcade::Input::LEFT);
  // 	    std::cerr << "left" << std::endl;
  // 	    break;
  // 	  case (static_cast<uint16_t>(arcade::CommandType::GO_RIGHT)):
  // 	    std::cerr << "right" << std::endl;
  // 	    fox.sendInput(Arcade::Input::RIGHT);
  // 	    break;
  // 	  case (static_cast<uint16_t>(arcade::CommandType::PLAY)):
  // 	    std::cerr << "play" << std::endl;
  // 	    fox.tick();
  // 	    break;
  // 	  }
  //   	cmd = 0;
  //     }
}
