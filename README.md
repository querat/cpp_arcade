# cpp_arcade
  
The goal of this project is to handle dynamic libraries on the fly in c++.  
  
It consists of 3 dynamic graphical libraries (interfacing respectively OpenGL, SFML and ncurses) and 2 dynamic games libs, all handled by a core program.  

you'll need ncurses, opengl and SFML  
  
usage: ./arcade lib/lib_arcade_XXXX.so  
  
Keys:
2, 3   > prev/next graphical lib  
4, 5   > prev/next game  
8      > restart game  
space  > shoot a projectile  
arrows > move around  
  
stdin inputs might not work on some terminals (I shamelessly casted the escape sequences inputs from the terminal to integers)

this project was corrected by a bot that uses the rules all, clean, fclean and re from the Makefile to compile the games, you'll therefore need to use make ALL, CLEAN, FCLEAN and RE in order to compile the whole project (core and dynamic .so libraries for both the games and the graphical libs)
