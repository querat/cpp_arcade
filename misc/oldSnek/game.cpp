//
// Created by lina_a on 21/03/16.
//

#include <GL/gl.h>
#include <sstream>
#include <GL/glut.h>
#include "game.hpp"
#include "Painter.hpp"

void Game::tick()
{
    if (!_snake.tick(_field))
    {
        _snake = Snake();
        _field = Field();
    }
}

void Game::draw(Painter &painter)
{
    _field.draw(painter);
}

void Game::keyEvent(Snake::Direction d)
{
    _snake.KeyEvent(d);
}

void Game::drawBitmap(float x, float y)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2f(x, y);
    std::stringstream   strm;
    strm << _snake.score;
    std::string test = strm.str();
    for (std::string::iterator it = test.begin(); it != test.end(); ++ it)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it);
}