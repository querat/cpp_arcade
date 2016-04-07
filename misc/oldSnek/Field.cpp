//
// Created by lina_a on 21/03/16.
//

#include <cstdlib>
#include <iostream>
#include "Painter.hpp"
#include "field.hpp"

Field::Field()
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH ; ++j)
            m_[i][j] = EMPTY;
    }
    newFruit();
}

void Field::draw(Painter &painter) const
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH ; ++j)
        {
            switch (m_[i][j])
            {
                case EMPTY:
                break;
                case SNAKE_BLOCK:
                    painter.bar(j * BLOCK_WIDTH, i * BLOCK_WIDTH,
                                (j + 1) * BLOCK_WIDTH - 1,
                                (i + 1) * BLOCK_WIDTH - 1);
                    break;
                case FRUIT:
                    painter.circle(j * BLOCK_WIDTH + BLOCK_WIDTH / 2,
                    i * BLOCK_HEIGHT + BLOCK_HEIGHT/ 2 ,
                    BLOCK_WIDTH / 2 - 1);
                    break;
            }
        }
    }
}

Field::Type Field::block(int x, int y) const
{
    return m_[y][x];
}

void Field::setBlock(Type type, int x, int y)
{
    m_[y][x] = type;
}

void Field::newFruit() {
    int     x;
    int     y;
    do
    {
       x = rand() % WIDTH;
        y = rand() % HEIGHT;
    }
    while (block(x, y) != EMPTY);
    setBlock(FRUIT, x, y);
}