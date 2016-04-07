//
// Created by lina_a on 21/03/16.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "Painter.hpp"
#include "field.hpp"
#include "game.hpp"

static Game    game;

void    display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    game.drawBitmap(10.0, 20.0);
    Painter paint;
    game.draw(paint);
    glutSwapBuffers();
}

void    Timer(int = 0)
{
    if (game._snake.speed >= 100)
        game._snake.speed = 100;
    game.tick();
    display();
    glutTimerFunc(150 - game._snake.speed, Timer, 0);
}

void    keyEvent(int key, int, int)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            game.keyEvent(Snake::LEFT);
            break;
        case GLUT_KEY_UP:
            game.keyEvent(Snake::UP);
            break;
        case GLUT_KEY_RIGHT:
            game.keyEvent(Snake::RIGHT);
            break;
        case GLUT_KEY_DOWN:
            game.keyEvent(Snake::DOWN);
            break;
    }
}

void    GestionClavier(unsigned char key, int, int)
{
    switch (key)
    {
        case 27:
            exit(EXIT_SUCCESS);
        case 'q':
            game.keyEvent(Snake::LEFT);
            break;
        case 'z':
            game.keyEvent(Snake::UP);
            break;
        case 'd':
            game.keyEvent(Snake::RIGHT);
            break;
        case 's':
            game.keyEvent(Snake::DOWN);
            break;
    }
}

int     main(int ac, char **av)
{
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Field::WIDTH * Field::BLOCK_WIDTH,
                       Field::HEIGHT * Field::BLOCK_HEIGHT);
    glutInitWindowPosition(100, 780);
    glutCreateWindow("Snake");
    glClearColor(0,0,0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Field::WIDTH * Field::BLOCK_WIDTH,
            Field::HEIGHT * Field::BLOCK_HEIGHT, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutSpecialFunc(keyEvent);
    glutKeyboardFunc(GestionClavier);
    Timer();
    glutMainLoop();
}