//
// DlLoader.hh for  in /home/querat_g/tmp/cpp_arcade/src
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Sun Mar 27 10:21:02 2016 querat_g
// Last update Sun Apr  3 14:43:07 2016 querat_g
//

#ifndef DLLOADER_HH_
# define DLLOADER_HH_

#include <iostream>
#include "IGraphicLib.hh"
#include "IGame.hh"

class DlLoader
{
private:
  std::string	_path;
  void		*_handle;

public:
  DlLoader(void);
  DlLoader(std::string const &path);
  ~DlLoader();
public:
  bool		openLib(std::string const &path);
  bool		closeLib(void);
  bool		dlSym(std::string const &name, void **sym) const;
  bool		isLoaded(void) const;
  IGraphicLib	*getLib(void) const;
  IGame		*getGame(void) const;
};

#endif // !DlLoader.hh
