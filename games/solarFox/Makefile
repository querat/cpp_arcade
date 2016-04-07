##
## Makefile<5> for  in /home/querat_g/tmp/cpp_arcade
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Mar 16 10:27:16 2016 querat_g
## Last update Sat Apr  2 17:23:46 2016 querat_g
##

RM		=	rm -f

CXX		=	g++

INCFLAGS	+=	-I./include
INCFLAGS	+=	-I./src
INCFLAGS	+=	-I../../include/

CXXFLAGS 	=	-W -Wall -Wextra -std=c++11 -fPIC
CXXFLAGS 	+=	$(INCFLAGS)
CXXFLAGS 	+=	$(LDFLAGS)
CXXFLAGS	+=	-g

NAME		=	../lib_arcade_solarfox.so

SRCS		=	src/SolarFox.cpp \
			src/Enemy.cpp \
			src/Projectile.cpp \
			src/Player.cpp \
			src/Merdinette.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME) 

$(NAME):		$(OBJS)
			$(CXX) -shared -fPIC -o $(NAME) $(OBJS) \
			$(CXXFLAGS)

test:			$(OBJS)
			$(CXX) -o a.out $(OBJS) $(CXXFLAGS) -DDEBUG

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
