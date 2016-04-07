##
## Makefile<5> for  in /home/querat_g/tmp/cpp_arcade
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Mar 16 10:27:16 2016 querat_g
## Last update Fri Apr  1 16:33:53 2016 querat_g
##

RM		=	rm -f

CXX		=	g++

INCFLAGS	+=	-I./include
INCFLAGS	+=	-I./src
INCFLAGS	+=	-I../../include/
INCFLAGS	+=	-I../include/

CXXFLAGS 	=	-W -Wall -Wextra -std=c++11 -fPIC
CXXFLAGS 	+=	$(INCFLAGS)
CXXFLAGS 	+=	$(LDFLAGS)
CXXFLAGS	+=	-g

NAME		=	../lib_arcade_snake.so

SRCS		=	src/Snake.cpp \
			src/Field.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CXX) -shared -fPIC -o $(NAME) $(OBJS) \
			$(CXXFLAGS)

test:			$(NAME)
			$(CXX) -o a.out test.c -L.. -l_arcade_snake $(CXXFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
