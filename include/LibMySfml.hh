//
// libMySfml.hh<2> for  in /home/querat_g/tmp/cpp_arcade/lib/SFML/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 10:23:20 2016 querat_g
// Last update Thu Apr  7 10:17:30 2016 querat_g
//

#ifndef LIBMYSFML_HH_
# define LIBMYSFML_HH_

# include <map>
# include <vector>
# include <utility>
# include <SFML/Graphics.hpp>
# include "Protocol.hpp"
# include "IGraphicLib.hh"

# define SF_TILE_SIZE	48
# define SF_WIDTH	(MAP_WIDTH * SF_TILE_SIZE)
# define SF_HEIGHT      (MAP_HEIGHT * SF_TILE_SIZE)

typedef std::map<Arcade::Color, sf::Color> t_colorMap;

typedef std::vector<std::pair<sf::Keyboard::Key, Arcade::Input>> t_keyVector;
typedef t_keyVector::iterator					 t_keyVectorIterator;

class	LibMySfml : public IGraphicLib
{
private:
  sf::RenderWindow	*_win;
  t_colorMap		_colorMap;
  t_keyVector		_keyMap;

private:


public:
  LibMySfml();
  ~LibMySfml();

  void			test(void) const;
  void			refresh();
  void			destroyWindow();
  void			clearWindow();
  void			drawSquare(size_t x, size_t y, Arcade::Color color);
  Arcade::Input		pollEvents();
};

#endif
