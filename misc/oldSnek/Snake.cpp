//
// Created by lina_a on 21/03/16.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "snake.hpp"

Snake::Snake() : _direction(static_cast<Direction>(rand() % 4))
{
    _blocks.push_back(std::pair<int, int>
            (Field::WIDTH / 2,
            Field::HEIGHT / 2));
    _blocks.push_back(std::pair<int, int>
            (Field::WIDTH / 2,
            Field::HEIGHT / 2));
    _blocks.push_back(std::pair<int, int>
            (Field::WIDTH / 2,
            Field::HEIGHT / 2));
    _blocks.push_back(std::pair<int, int>
            (Field::WIDTH / 2,
            Field::HEIGHT / 2));
}

void Snake::KeyEvent(Direction d)
{
    if (d == _direction)
        return;
    switch (d)
    {
        case LEFT:
            if (_direction == RIGHT)
                return;
            break;
        case UP:
            if (_direction == DOWN)
                return;
            break;
        case RIGHT:
            if (_direction == LEFT)
                return;
            break;
        case DOWN:
            if (_direction == UP)
                return;
            break;
    }
    _direction = d;
}

bool Snake::tick(Field &f)
{
    std::pair<int ,int> p = _blocks.front();
    switch (_direction)
    {
        case LEFT:
            p.first--;
            break;
        case UP:
            p.second--;
            break;
        case RIGHT:
            p.first++;
            break;
        case DOWN:
            p.second++;
            break;
    }
    if (p.first < 0 || p.first >= Field::WIDTH ||
        p.second < 0 ||
        p.second >= Field::HEIGHT)
    {
      std::cout << "Enter your name" << std::endl;
        std::cin >> _name;
        std::ofstream outputfile("score.txt", std::ios_base::app);
        outputfile << _name << ":" << score << std::endl;
        outputfile.close();
        exit(EXIT_SUCCESS);
    }
    if (f.block(p.first, p.second) == Field::SNAKE_BLOCK)
    {
        std::cout << "Enter your name" << std::endl;
        std::cin >> _name;
        std::ofstream outputfile("score.txt", std::ios_base::app);
        outputfile << _name << ":" << score << std::endl;
        outputfile.close();
        exit(EXIT_SUCCESS);
    }
    _blocks.push_front(p);
    if (f.block(p.first, p.second) != Field::FRUIT)
    {
        f.setBlock(Field::SNAKE_BLOCK, p.first, p.second);
        std::pair<int ,int> p = _blocks.back();
        f.setBlock(Field::EMPTY, p.first, p.second);
        _blocks.pop_back();

    }
    else
    {
        score += 10;
        speed += 8;
        f.setBlock(Field::SNAKE_BLOCK, p.first, p.second);
        f.newFruit();
    }
    return _blocks.size() < Field::WIDTH * Field::HEIGHT;
}
