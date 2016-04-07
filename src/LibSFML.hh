//
// LibSFML.hh for  in /home/querat_g/tmp/cpp_arcade/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sun Mar 27 14:11:16 2016 querat_g
// Last update Mon Mar 28 10:37:33 2016 querat_g
//

#ifndef LIBSFML_HH_
# define LIBSFML_HH_

#include "Protocol.hpp"
#include "IGraphicLib.hh"

class		LibSFML : public IGraphicLib
{
public:
  ~LibSFML();
  LibSFML(std::string const &path);

private:


public:
  bool		openWindow(size_t x, size_t y) const;
  void		drawEntity(arcade::TileType type, size_t x, size_t y) const;
  void		refresh();
  void		destroyWindow();


};

#endif
