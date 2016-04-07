//
// SolarFox.hh for  in /home/querat_g/tmp/cpp_arcade/games/solarFox
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 19:52:44 2016 querat_g
// Last update Sun Apr  3 14:33:00 2016 querat_g
//

#ifndef SOLARFOX_HH_
# define SOLARFOX_HH_

# include <map>
# include <list>
# include <utility>
# include "Definitions.hh"
# include "IGame.hh"
# include "Enemy.hh"
# include "Player.hh"
# include "Projectile.hh"
# include "Protocol.hpp"

# define SOLARFOX_USLEEP                 50000
# define SOLARFOX_EVIL_SHOOT_CHANCE      10

typedef std::map<Arcade::Input, Enemy>   t_enemyMap;
typedef std::list<Projectile*>           t_ProjectileList;

class	SolarFox : public IGame
{
private:
  Arcade::Tile			_map[MAP_WIDTH * MAP_HEIGHT];
  t_enemyMap			_enemies;
  t_ProjectileList		_projectiles;
  Player			_player;

public:
  SolarFox();
  ~SolarFox();
  void				startGame();
  void				exitGame();
  void				restartGame();
  void				sendInput(Arcade::Input);
  void				tick();
  Arcade::Tile const *		getMap() const;
  void				writeMap();
  void				whereAmI() const;
  arcade::TileType		getTileAtPos(int x, int y);


private:
  void				createEnemies();
  void				clearMap();
  void				reDrawMap();
  void				drawProjectiles();
  void				reDrawClipWall();
  void				drawEnemies();
  void				deleteProjectiles();
};

#endif // !SolarFox.hh
