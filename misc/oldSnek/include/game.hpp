//
// Created by lina_a on 21/03/16.
//

#ifndef RETRY_OPENGL_GAME_HPP
#define RETRY_OPENGL_GAME_HPP

#include "field.hpp"
#include "snake.hpp"

class   Game{
public:
    void    tick();
    void    draw(Painter &);
    void    keyEvent(Snake::Direction);
    void    drawBitmap(float  x, float y);
    Snake   _snake;
private:
    Field   _field;
};

#endif //RETRY_OPENGL_GAME_HPP
