##
## MakefileSFML for  in /home/querat_g/tmp/cpp_arcade
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Mar 16 09:12:04 2016 querat_g
## Last update Mon Mar 28 10:25:05 2016 querat_g
##

RM		=	rm -f

CXX		=	g++

INCFLAGS	=	-I./lib/SFML/include
INCFLAGS	+=	-I../../include/
INCFLAGS	+=	-I../../src/
INCFLAGS	+=	-I./include/
LDFLAGS		+=	-L./lib/
LDFLAGS		+=	-lsfml-system
LDFLAGS		+=	-lsfml-window
LDFLAGS		+=	-lsfml-graphics	
LDFLAGS		+=	-lsfml-audio

CXXFLAGS 	=	-W -Wall -Wextra -std=c++11 -fPIC
CXXFLAGS 	+=	$(INCFLAGS)
CXXFLAGS 	+=	$(LDFLAGS)
CXXFLAGS	+=	-g

SFMLNAME	=	../lib_arcade_SFML.so

SFMLSRCS	=	src/mainSFML.cpp \

SFMLOBJS	=	$(SFMLSRCS:.cpp=.o)

$(SFMLNAME):		$(SFMLOBJS)
			$(CXX) -shared -fPIC -o $(SFMLNAME) $(SFMLOBJS) \
			$(CXXFLAGS)

all:			$(SFMLNAME) 

clean:
			$(RM) $(SFMLOBJS)

fclean:			clean
			$(RM) $(SFMLNAME)

re:			fclean all

.PHONY:			all clean fclean re
