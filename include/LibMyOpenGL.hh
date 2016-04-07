//
// LibMyOpenGL.hh for  in /home/querat_g/tmp/cpp_arcade/lib/SFML/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Mon Mar 28 12:10:09 2016 querat_g
// Last update Sun Apr  3 13:48:40 2016 querat_g
//

#ifndef LIBMYOPENGL_HH_
# define LIBMYOPENGL_HH_

# include <map>
# include <vector>
# include <utility>
#include "Protocol.hpp"
#include "IGraphicLib.hh"

#define GL_WIDTH	20
#define GL_HEIGHT	10
#define GL_TAIL 32
enum ColorGL
{
    REDGL = GL_RED,
    GREENGL = GL_GREEN,
    BLUEGL = GL_BLUE
};

typedef std::map<Arcade::Color, std::vector<float> > t_colormap;

typedef std::vector<std::pair<sf::Keyboard::Key, Arcade::Input>> t_keyVector;
typedef t_keyVector::iterator t_keyVectorIterator;


class	LibMyOpenGL : public IGraphicLib
{
public:
  LibMyOpenGL();
  ~LibMyOpenGL();

  void			test(void) const;
  void			refresh();
  void			destroyWindow();
  void			clearWindow();
  void			drawSquare(size_t x, size_t y, Arcade::Color color);
  Arcade::Input		pollEvents();
private:
  sf::RenderWindow	*_win;
  t_colormap		_colomap;
  t_keyVector		_keyMap;
    float           _pixHeight;
    float           _pixWidth;
};

#endif
