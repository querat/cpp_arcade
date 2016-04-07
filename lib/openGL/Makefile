##
## MakefileOPENGL for  in /home/querat_g/tmp/cpp_arcade
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Mar 16 09:12:04 2016 querat_g
## Last update Tue Mar 29 14:18:20 2016 querat_g
##

RM		=	rm -f

CXX		=	g++

INCFLAGS	=	-I../SFML/include/SFML/
INCFLAGS	+=	-I../../include/
INCFLAGS	+=	-I../../src/

LDFLAGS		+=	-L./lib/

LDFLAGS		+=	-lsfml-window
LDFLAGS		+=	-lsfml-graphics	
LDFLAGS		+=	-lGL

CXXFLAGS 	=	-W -Wall -Wextra -std=c++11 -fPIC
CXXFLAGS 	+=	$(INCFLAGS)
CXXFLAGS 	+=	$(LDFLAGS)
CXXFLAGS	+=	-g

OPENGLNAME	=	../lib_arcade_OPENGL.so

OPENGLSRCS	=	src/LibMyOpenGL.cpp \

OPENGLOBJS	=	$(OPENGLSRCS:.cpp=.o)

$(OPENGLNAME):		$(OPENGLOBJS)
			$(CXX) -shared -fPIC -o $(OPENGLNAME) $(OPENGLOBJS) \
			$(CXXFLAGS)

all:			$(OPENGLNAME) 

clean:
			$(RM) $(OPENGLOBJS)

fclean:			clean
			$(RM) $(OPENGLNAME)

re:			fclean all

.PHONY:			all clean fclean re
