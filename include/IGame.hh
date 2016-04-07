//
// Igame.hh for  in /home/querat_g/tmp/cpp_arcade/lib/SFML
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 18:19:34 2016 querat_g
// Last update Sat Apr  2 14:40:50 2016 querat_g
//

#ifndef	IGAME_HH_
# define IGAME_HH_

#include "Definitions.hh"

class	IGame
{
public:
  IGame(){}
  virtual				~IGame(){}
  virtual void				startGame() = 0;
  virtual void				exitGame() = 0;
  virtual void				restartGame() = 0;
  virtual void				sendInput(Arcade::Input) = 0;
  virtual void				tick() = 0;
  virtual Arcade::Tile const *		getMap() const = 0;

};

extern "C" IGame	*loadGame();
extern "C" void		Play();

#endif
