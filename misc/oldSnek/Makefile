##
## Makefile for  in /home/querat_g/piscine/piscine_cpp_d01/ex01
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Jan  6 14:27:54 2016 querat_g
## Last update Tue Feb  9 11:40:59 2016 querat_g
##

RM	=	rm -f

CC	=	clang++

NAME	= snake_Opengl

CXXFLAGS +=	-W -Wall -Wextra -std=c++11 -lGL -lglut -I./include

SRCS	= Field.cpp \
	  game.cpp \
	  main.cpp \
	  Painter.cpp \
	  Snake.cpp

OBJS	= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(CXXFLAAGS) -lGL -lglut $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all
