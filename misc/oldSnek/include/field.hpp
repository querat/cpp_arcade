//
// Created by lina_a on 21/03/16.
//

#ifndef RETRY_OPENGL_FIELD_HPP
#define RETRY_OPENGL_FIELD_HPP

class Painter;

class Field{
public:
    enum {
        WIDTH = 40,
        HEIGHT = 40
    };
    enum {
        BLOCK_WIDTH = 20,
        BLOCK_HEIGHT = 20
    };
    enum Type
    {
        EMPTY,
        SNAKE_BLOCK,
        FRUIT
    };
    Field();
    void setBlock(Type type, int, int);
    Type block(int x, int y) const;
    void draw(Painter &) const;
    void newFruit();
private:
    Type    m_[HEIGHT][WIDTH];
};

#endif //RETRY_OPENGL_FIELD_HPP
