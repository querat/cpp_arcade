//
// mainSFML.cpp for  in /home/querat_g/tmp/cpp_arcade/src/SFML
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Tue Mar 15 19:02:06 2016 querat_g
// Last update Sun Apr  3 15:48:43 2016 querat_g
//

#include <iostream>
#include "LibMySfml.hh"
#include "DlLoader.hh"

void
LibMySfml::test(void) const
{
  std::cerr << "libMySfml OK !" << std::endl;
}

LibMySfml::LibMySfml()
  : _win(new sf::RenderWindow(sf::VideoMode(SF_WIDTH, SF_HEIGHT), "Snek", sf::Style::Close))
{
  std::cerr << "constructing LibMySfml" << std::endl;
  this->clearWindow();
  this->refresh();

  // Arcade::Color to sf::Color map
  this->_colorMap.insert(std::make_pair(Arcade::BLACK,  sf::Color::Black));
  this->_colorMap.insert(std::make_pair(Arcade::ORANGE, sf::Color(255, 102, 0)));
  this->_colorMap.insert(std::make_pair(Arcade::YELLOW, sf::Color::Yellow));
  this->_colorMap.insert(std::make_pair(Arcade::RED,    sf::Color::Red));
  this->_colorMap.insert(std::make_pair(Arcade::PURPLE, sf::Color(255, 50, 255)));
  this->_colorMap.insert(std::make_pair(Arcade::BLUE,   sf::Color::Blue));
  this->_colorMap.insert(std::make_pair(Arcade::GREEN,  sf::Color::Green));
  this->_colorMap.insert(std::make_pair(Arcade::CYAN,   sf::Color::Cyan));

  // Pairs vector used by pollEvents
  this->_keyMap = t_keyVector
    ({
        std::make_pair(sf::Keyboard::Up,     Arcade::UP   ),
	std::make_pair(sf::Keyboard::Down,   Arcade::DOWN ),
	std::make_pair(sf::Keyboard::Left,   Arcade::LEFT ),
	std::make_pair(sf::Keyboard::Right,  Arcade::RIGHT),
	std::make_pair(sf::Keyboard::Num1,   Arcade::ONE  ),
	std::make_pair(sf::Keyboard::Num2,   Arcade::TWO  ),
	std::make_pair(sf::Keyboard::Num3,   Arcade::THREE),
	std::make_pair(sf::Keyboard::Num4,   Arcade::FOUR ),
	std::make_pair(sf::Keyboard::Num5,   Arcade::FIVE ),
	std::make_pair(sf::Keyboard::Num8,   Arcade::EIGHT),
	std::make_pair(sf::Keyboard::Num9,   Arcade::NINE ),
	std::make_pair(sf::Keyboard::Escape, Arcade::ESC  ),
	std::make_pair(sf::Keyboard::Space,  Arcade::SPACE  )
    });
}

LibMySfml::~LibMySfml()
{
  std::cerr << "destructing LibMySfml" << std::endl;
  this->destroyWindow();
}

void
LibMySfml::drawSquare(size_t x, size_t y, Arcade::Color color)
{
  // sf::RectangleShape	rect(sf::Vector2f(SF_TILE_SIZE, SF_TILE_SIZE));
  sf::CircleShape	rect((SF_TILE_SIZE - 4) / 2);

  rect.setFillColor(this->_colorMap.at(color));
  rect.setPosition(SF_TILE_SIZE * x, SF_TILE_SIZE * y);
  this->_win->draw(rect);
}

void
LibMySfml::refresh()
{
  this->_win->display();
}

void
LibMySfml::destroyWindow()
{
  if (this->_win)
    {
      delete this->_win;
      this->_win = 0x0;
    }
}

void
LibMySfml::clearWindow()
{
  this->_win->clear(sf::Color::Black);
}

Arcade::Input
LibMySfml::pollEvents()
{
  t_keyVectorIterator	it;

  it = this->_keyMap.begin();
  while (it != this->_keyMap.end())
    {
      if (sf::Keyboard::isKeyPressed(it->first))
	return (it->second);
      ++it;
    }
  return (Arcade::NONE);
}

extern "C"
{
  IGraphicLib*
  loadLibrary()
  {
    return (new LibMySfml());
  }
}
