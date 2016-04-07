//
// DlLoader.cpp for  in /home/querat_g/tmp/cpp_arcade/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sun Mar 27 10:24:11 2016 querat_g
// Last update Sun Apr  3 14:43:02 2016 querat_g
//

#include <dlfcn.h>
#include "DlLoader.hh"

DlLoader::DlLoader(std::string const &path)
  : _path(std::string(path))
  , _handle(0x0)
{}

DlLoader::DlLoader(void)
  : _path(std::string("default"))
  , _handle(0x0)
{}

DlLoader::~DlLoader(void)
{
  this->closeLib();
}

bool
DlLoader::closeLib(void)
{
  char	*err;

  if (!_handle)
    return (false);
  std::cout << "attempting to close lib " << this->_path << std::endl;
  dlerror(); // flush dlerror before calling dlClose
  dlclose(_handle);
  this->_handle = 0x0;
  err = dlerror();
  if (err)
    {
      std::cerr << "DlLoader::closeLib(): " << err << std::endl;
      return (false);
    }
  std::cerr << "library " << this->_path << " closing succeeded !" << std::endl;
  this->_path = std::string("");
  return (true);
}

bool
DlLoader::isLoaded(void) const
{
  return (this->_handle != 0x0);
}

bool
DlLoader::openLib(std::string const &path)
{
  char const	*cStr = path.c_str();
  char		*err;

  if (this->_handle)
    this->closeLib();

  // flush dlerror before calling dlOpen
  dlerror();
  this->_handle = dlopen(cStr, RTLD_NOW);
  err = dlerror();
  if (err)
    return (false);
  this->_path = std::string(path);
  return (true);
}

bool
DlLoader::dlSym(std::string const &name, void **sym) const
{
  char		*err;

  if (sym == 0x0)
    return (false);

  dlerror();
  (*sym) = dlsym(this->_handle, name.c_str());
  err = dlerror();
  if (err)
    {
      (*sym) = 0x0;
      std::cerr << "DlLoader::dlSym: " << err << std::endl;
      return (false);
    }
  return (true);
}

IGraphicLib*
DlLoader::getLib(void) const
{
  void		*sym = 0x0;
  IGraphicLib	*(*lib)() = 0x0;

  dlSym("loadLibrary", &sym);
  if (!sym)
    return (0x0);
  lib = reinterpret_cast<IGraphicLib*(*)()>(sym);
  return ((lib)());
}

IGame*
DlLoader::getGame(void) const
{
  void		*sym = 0x0;
  IGame		*(*game)() = 0x0;

  dlSym("loadGame", &sym);
  if (!sym)
    return (0x0);
  game = reinterpret_cast<IGame*(*)()>(sym);
  return ((game)());
}
