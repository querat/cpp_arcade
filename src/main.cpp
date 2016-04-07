//
// main.cpp for  in /home/querat_g/tmp/cpp_arcade
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 14 11:29:12 2016 querat_g
// Last update Thu Apr  7 10:58:54 2016 querat_g
//

#include <signal.h>

#include <iostream>
#include <string>
#include "Protocol.hpp"
#include "LibMySfml.hh"
#include "DlLoader.hh"
#include "LibSFML.hh"
#include "IGame.hh"
#include "ArcadeCore.hh"
#include "Definitions.hh"

static ArcadeCore	*g_core = NULL;

void	sigint(int sig)
{
  (void)sig;
  std::cerr << "Arcade: SIGINT caught, "
	    << "exiting properly !"
	    << std::endl;
  if (g_core)
    g_core->setExitState(true);
}

int	main(int ac, char **argv)
{
  if (ac != 2)
    {
      std::cerr << "usage: ./arcade ./path/to/libGraphic.so" << std::endl;
      return (1);
    }
  ArcadeCore	*arcade = 0x0;

  try {
    arcade = new ArcadeCore(argv[1]);
  }
  catch (std::exception){
    std::cerr << "error while loading a dynamic library" << std::endl;
    return (1);
  }

  signal(SIGINT, &sigint);

  // mode Raw du terminal, pour l'acquisition des inputs clavier
  Arcade::rawMode();

  arcade->loadGame("games/lib_arcade_snake.so");

  // Nécessaire pour exit proprement avec un ^C
  g_core = arcade;

  arcade->loop();

  // mode canonique restauré
  Arcade::canonMode();

  delete (arcade);
  return (0);
}
