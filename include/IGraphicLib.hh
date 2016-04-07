//
// IGraphicLib.hh for  in /home/querat_g/tmp/cpp_arcade/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sun Mar 27 12:01:55 2016 querat_g
// Last update Sun Apr  3 13:48:49 2016 querat_g
//

#ifndef IGRAPHICLIB_HH_
# define IGRAPHICLIB_HH_

# include <string>
# include "Protocol.hpp"
# include "Definitions.hh"

class	IGraphicLib
{
public:
  virtual ~IGraphicLib(){}
  IGraphicLib(){}

public:
  virtual void			test(void) const = 0;
  virtual void			refresh() = 0;
  virtual void			destroyWindow() = 0;
  virtual void			clearWindow() = 0;
  virtual void			drawSquare(size_t x, size_t y, Arcade::Color color) = 0;
  virtual Arcade::Input		pollEvents() = 0;
};

extern "C" IGraphicLib		*loadLibrary();


#endif // !IgraphicLib.hh
