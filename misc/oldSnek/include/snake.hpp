//
// Created by lina_a on 21/03/16.
//

#ifndef RETRY_OPENGL_SNAKE_HPP
#define RETRY_OPENGL_SNAKE_HPP

#pragma once

#include <list>
#include <string>
#include "field.hpp"

class   Snake{
public:
    enum Direction{
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Snake();
    bool    tick(Field &);
    void    KeyEvent(Direction);
    unsigned int    speed;
    int         score;
private:
    typedef std::list<std::pair<int, int> > Blocks;
    Blocks  _blocks;
    Direction   _direction;
    std::string _name;
};

#endif //RETRY_OPENGL_SNAKE_HPP
