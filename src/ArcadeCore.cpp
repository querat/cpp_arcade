//
// Core.cpp for  in /home/querat_g/tmp/cpp_arcade
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Tue Mar 29 09:35:34 2016 querat_g
// Last update Sun Apr  3 14:50:52 2016 querat_g
//

#include <map>

#include <unistd.h>

#include <iostream>
#include "ArcadeCore.hh"

ArcadeCore::ArcadeCore(std::string const &path)
  : _game(0x0)
  , _gamesTab(t_libsTab({GAME_SNEK, GAME_SOLAR}))
  , _lib(0x0)
  , _libsTab(t_libsTab({LIB_SF, LIB_GL, LIB_NCURSES}))
  , _exiting(false)
  , _itLibs(0)
  , _itGames(0)
  , _currentInput(Arcade::NONE)
{
  if ((!(_libLoader.openLib(path)))  ||
      (!(_lib = _libLoader.getLib()) ))
    {
      throw std::exception();
    }

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
	std::make_pair(27,      Arcade::ESC  )
    });
}

void ArcadeCore::setExitState(bool state){ _exiting = state; }

bool
ArcadeCore::closeGame()
{
  if (this->_game != 0x0)
    {
      delete (this->_game);
      this->_game = 0x0;
      this->_map = 0x0;
      if (!this->_gameLoader.closeLib())
	return (false);
    }
  return (true);
}

bool
ArcadeCore::closeLib()
{
  if (this->_lib != 0x0)
    {
      delete (this->_lib);
      this->_lib = 0x0;
      if (!this->_libLoader.closeLib())
	return (false);
    }
  usleep(LIB_SWAP_DELAY);
  return (true);
}

ArcadeCore::~ArcadeCore()
{
  this->closeGame();
  if (this->_lib)
    {
      delete (this->_lib);
      this->_libLoader.closeLib();
    }
}

bool
ArcadeCore::loadLib(std::string const &path)
{
  // closes the currently opened library if it exists
  this->closeLib();

  if (!_libLoader.openLib(path))
    {
      // shit happens
      return (false);
    }
  if (!(this->_lib = _libLoader.getLib()))
    {
      // couldn't interface the lib
      this->_libLoader.closeLib();
      return (false);
    }
  return (true);
}

bool
ArcadeCore::loadGame(std::string const &game)
{
  // if there is a game loaded at this moment, close it
  this->closeGame();

  if (!_gameLoader.openLib(game))
    {
      // shit happens
      return (false);
    }
  if (!(_game = _gameLoader.getGame()))
    {
      // invalid game.so
      _gameLoader.closeLib();
      return (false);
    }
  usleep(LIB_SWAP_DELAY);
  return (true);
}

void
ArcadeCore::restartGame() const
{
  if (this->_game)
    this->_game->restartGame();
}

void
ArcadeCore::nextLib()
{
  this->_itLibs = (this->_itLibs + 1) % NB_LIBS;

  std::cerr << "ArcadeCore::nextlib(): loading graphical library "
	    << _libsTab.at(_itLibs)
	    << std::endl;
  this->loadLib(_libsTab.at(_itLibs));
}

void
ArcadeCore::previousLib()
{
  --_itLibs;
  if (_itLibs < 0)
    _itLibs = (NB_LIBS - 1);

  std::cerr << "ArcadeCore::previousLib(): loading graphical library "
	    << _libsTab.at(_itLibs)
	    << std::endl;
  this->loadLib(_libsTab.at(_itLibs));
}

void
ArcadeCore::nextGame()
{
  this->_itGames = (this->_itGames + 1) % NB_GAMES;

  std::cerr << "ArcadeCore::nextgame(): loading game library "
	    << _gamesTab.at(_itGames)
	    << std::endl;
  this->loadGame(_gamesTab.at(_itGames));
}

void
ArcadeCore::previousGame()
{
  --_itGames;
  if (_itGames < 0)
    _itGames = (NB_GAMES - 1);

  std::cerr << "ArcadeCore::previousGame(): loading game library "
	    << _gamesTab.at(_itGames)
	    << std::endl;
  this->loadGame(_gamesTab.at(_itGames));
}

void
ArcadeCore::backToMenu()
{
  this->closeGame();
}

Arcade::Input
ArcadeCore::_parseStdin() const
{
  int				buffer = 0;
  t_stdinKeyMap::const_iterator	it = this->_keyMap.begin();

  read(STDIN_FILENO, &buffer, sizeof(buffer));
  while (it != _keyMap.end())
    {
      if (buffer == it->first)
	return (it->second);
      ++it;
    }

  return (Arcade::NONE);
}

void
ArcadeCore::_parseInput()
{
  switch (_currentInput)
    {
    case Arcade::ESC:
      _exiting = true;
      break;
    case Arcade::TWO:
      this->previousLib();
      break;
    case Arcade::THREE:
      this->nextLib();
      break;
    case Arcade::FOUR:
      this->previousGame();
      break;
    case Arcade::FIVE:
      this->nextGame();
      break;
    case Arcade::EIGHT:
      this->restartGame();
      break;
     case Arcade::NINE:
      this->closeGame();
      break;
    default:
      {}
    }
}

Arcade::Color
entity_to_color(Arcade::Tile tile)
{
  static std::map<Arcade::Tile, Arcade::Color> hash({
      std::make_pair(Arcade::EMPTY , Arcade::BLACK),
	std::make_pair(Arcade::PLAYER, Arcade::GREEN),
	std::make_pair(Arcade::ITEM  , Arcade::CYAN ),
	std::make_pair(Arcade::ENEMY  , Arcade::YELLOW ),
	std::make_pair(Arcade::ENEMY_SHOT  , Arcade::RED ),
	std::make_pair(Arcade::PLAYER_SHOT  , Arcade::ORANGE )
	});
  return (hash[tile]);
}

void
ArcadeCore::drawGame() const
{
  Arcade::Color	color;

  if (!_map || !_lib)
    return ;

  _lib->clearWindow();
  for (int y = 0; y < MAP_HEIGHT; y++)
    {
      for (int x = 0; x < MAP_WIDTH; x++)
	{
	  color = entity_to_color(_map[(y * MAP_WIDTH) + x]);
	  _lib->drawSquare(x, y, color);
	}
    }
  _lib->refresh();
}

void
ArcadeCore::loop()
{
  while(!_exiting)
    {
      _currentInput = Arcade::NONE;

      // if there is a graphic lib loaded, grab its input
      if (_lib)
	_currentInput = _lib->pollEvents();
      else // otherwise, wait for the next input in stdin
	_currentInput = _parseStdin();

      // see if the core should handle that input
      _parseInput();

      // if there is a loaded game, process the input
      // then tick() the game
      // before finally drawing with the graphical libs
      if (_game && _lib)
	{
	  _game->sendInput(_currentInput);
	  _game->tick();
	  _map = _game->getMap();
	  drawGame();
	}
    }

  this->closeLib();
  this->closeGame();
}
