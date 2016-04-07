##
## Makefile<4> for  in /home/querat_g/tmp/cpp_arcade
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Mar 16 09:42:14 2016 querat_g
## Last update Tue Mar 29 10:41:52 2016 schmou_a
##

RM		=	rm -f

CXX		=	g++

INCFLAGS	=	-Ilib/NC/include
INCFLAGS	+=	-I../../include
INCFLAGS	+=	-I../../src
LDFLAGS		+=	-L./lib/
LDFLAGS		+=	-lncurses

CXXFLAGS 	=	-W -Wall -Wextra -std=c++11 -fPIC
CXXFLAGS 	+=	$(INCFLAGS)
CXXFLAGS 	+=	$(LDFLAGS)
CXXFLAGS	+=	-g

NCNAME		=	../lib_arcade_ncurses.so

NCSRCS		=	src/mainNcurses.cpp \

NCOBJS		=	$(NCSRCS:.cpp=.o)

$(NCNAME):		$(NCOBJS)
			$(CXX) -shared -fPIC -o $(NCNAME) $(NCOBJS) \
			$(CXXFLAGS)

all:			$(NCNAME)

clean:
			$(RM) $(NCOBJS)

fclean:			clean
			$(RM) $(NCNAME)

re:			fclean all

.PHONY:			all clean fclean re
