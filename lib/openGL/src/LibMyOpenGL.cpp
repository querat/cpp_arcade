//
// mainOpenGl.cpp for  in /home/querat_g/tmp/cpp_arcade/lib/openGL
//
// Made by querat_g
// Login   <querat_g@epitech.net>
//
// Started on  Wed Mar 16 09:35:47 2016 querat_g
// Last update Sun Apr  3 13:48:29 2016 querat_g
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "LibMyOpenGL.hh"
#include "DlLoader.hh"

void
LibMyOpenGL::test(void) const
{
  std::cerr << "libMyOpenGL OK !" << std::endl;
}

LibMyOpenGL::LibMyOpenGL() : _win(new sf::RenderWindow(sf::VideoMode(MAP_WIDTH * GL_TAIL, MAP_HEIGHT * GL_TAIL), "Snake",sf::Style::Close))
{
  glClearColor(0.f, 0.f, 0.f, 1.f);
  glViewport(0, 0, MAP_WIDTH * GL_TAIL, MAP_HEIGHT * GL_TAIL);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-0.5, MAP_WIDTH - 0.5, MAP_HEIGHT - 0.5, -0.5, -10, 10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);
  this->clearWindow();
  this->refresh();
  this->_colomap.insert(std::make_pair(Arcade::BLACK,  std::vector<float>{0.0f, 0.0f, 0.0f}));
  this->_colomap.insert(std::make_pair(Arcade::ORANGE, std::vector<float>{1.0f, 0.4f, 0.0f}));
  this->_colomap.insert(std::make_pair(Arcade::YELLOW, std::vector<float>{1.0f, 1.0f, 0.0f}));
  this->_colomap.insert(std::make_pair(Arcade::RED,    std::vector<float>{1.0f, 0.0f, 0.0f}));
  this->_colomap.insert(std::make_pair(Arcade::PURPLE, std::vector<float>{1.0f, 0.2f, 1.0f}));
  this->_colomap.insert(std::make_pair(Arcade::BLUE,   std::vector<float>{0.0f, 0.0f, 1.0f}));
  this->_colomap.insert(std::make_pair(Arcade::CYAN,   std::vector<float>{0.0f, 1.0f, 1.0f}));
  this->_colomap.insert(std::make_pair(Arcade::GREEN,  std::vector<float>{0.0f, 1.0f, 0.0f}));

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
      std::make_pair(sf::Keyboard::Space,  Arcade::SPACE)

     });
}

LibMyOpenGL::~LibMyOpenGL()
{
  std::cerr << "destructing LibMyOpenGL" << std::endl;
  delete (this->_win);
}

void LibMyOpenGL::refresh()
{
  this->_win->display();
}

void
LibMyOpenGL::destroyWindow()
{
  if (this->_win)
  {
    delete this->_win;
    this->_win = 0x0;
  }
}

void
LibMyOpenGL::clearWindow()
{
  this->_win->clear(sf::Color::Black);
}

void
LibMyOpenGL::drawSquare(size_t x, size_t y, Arcade::Color color)
{
  glPushMatrix();
  glTranslatef(x, y, 0.0f);
  glBegin(GL_QUADS);
  glColor3f(this->_colomap.at(color)[0],
            this->_colomap.at(color)[1],
            this->_colomap.at(color)[2]);
  glVertex2f(-0.4f, -0.4f);     // bas a gauche
  glVertex2f(0.4f, -0.4f);     // bas a Droite
  glVertex2f(0.4f, 0.4f);    //  haut a droite
  glVertex2f(-0.4f, 0.4f);    //  haut a gauche
  glEnd();
  glFlush();
  glPopMatrix();
}

Arcade::Input
LibMyOpenGL::pollEvents()
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
IGraphicLib*
loadLibrary()
{
  return (new LibMyOpenGL());
}
