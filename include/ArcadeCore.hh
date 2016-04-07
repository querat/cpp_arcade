//
// Core.hh for  in /home/querat_g/tmp/cpp_arcade
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Tue Mar 29 09:35:22 2016 querat_g
// Last update Sun Apr  3 14:52:41 2016 querat_g
//

#ifndef CORE_HH_
# define CORE_HH_

# include <string>
# include <vector>
# include <utility>
# include <vector>
# include "IGraphicLib.hh"
# include "IGame.hh"
# include "DlLoader.hh"

# define NB_LIBS	3
# define LIB_SF		"./lib/lib_arcade_SFML.so"
# define LIB_GL		"./lib/lib_arcade_OPENGL.so"
# define LIB_NCURSES	"./lib/lib_arcade_ncurses.so"

# define NB_GAMES	2
# define GAME_SNEK	"./games/lib_arcade_snake.so"
# define GAME_SOLAR	"./games/lib_arcade_solarfox.so"

# define LIB_NCURSES	"./lib/lib_arcade_ncurses.so"
# define LIB_SWAP_DELAY 250000

typedef std::vector<std::string>			t_libsTab;
typedef std::vector<std::string>::iterator		t_libsTabIt;

typedef std::vector<std::pair<int, Arcade::Input>>	t_stdinKeyMap;
typedef t_stdinKeyMap::iterator				t_stdinKeyMapIt;

class	ArcadeCore
{
public:
  ArcadeCore(std::string const &path);
  ~ArcadeCore();

private:
  IGame*			_game;
  t_libsTab			_gamesTab;
  DlLoader			_gameLoader;

  IGraphicLib*			_lib;
  t_libsTab			_libsTab;
  DlLoader			_libLoader;

  bool				_exiting;
  int				_itLibs;
  int				_itGames;
  t_stdinKeyMap			_keyMap;
  Arcade::Input			_currentInput;
  Arcade::Tile	const *		_map;

private:
  Arcade::Input	_parseStdin() const;
  void		_parseInput();

public:
  bool		loadGame(std::string const &path);
  bool		loadLib(std::string const &path);
  bool		closeGame();
  bool		closeLib();
  void		restartGame() const;
  void		nextLib();
  void		previousLib();
  void		nextGame();
  void		previousGame();
  void		backToMenu();
  void		loop();
  void		drawGame() const;
  void		setExitState(bool);
};

#endif // !Core.hh
