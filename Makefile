##
## Makefile for  in /home/querat_g/piscine/piscine_cpp_d01/ex01
## 
## Made by querat_g
## Login   <querat_g@epitech.net>
## 
## Started on  Wed Jan  6 14:27:54 2016 querat_g
## Last update Sun Apr  3 13:49:50 2016 querat_g
##

RM		=	rm -f

CXX		=	g++

INCFLAGS	=	-I./include
INCFLAGS	+=	-I./src

# dlopen() dlsym() dlclose()
LDFLAGS		=	-ldl
# GraphicLibs
LDFLAGS		+=	-L./lib
LDFLAGS		+=	-l_arcade_SFML
LDFLAGS		+=	-l_arcade_OPENGL
LDFLAGS		+=	-l_arcade_ncurses
# Games
LDFLAGS		+=	-L./games
LDFLAGS		+=	-l_arcade_snake
LDFLAGS		+=	-l_arcade_solarfox

CXXFLAGS 	=	-W -Wall -Wextra -std=c++11
CXXFLAGS 	+=	$(INCFLAGS)
CXXFLAGS 	+=	$(LDFLAGS)
CXXFLAGS	+=	-g

NAME		=	arcade

SRCS		=	src/main.cpp \
			src/DlLoader.cpp \
			src/ArcadeCore.cpp \
			src/Arcade.cpp \
			src/Exceptions.cpp

OBJS		=	$(SRCS:.cpp=.o)

# Moulimerde
all:			games
clean:			gamesclean
fclean:			gamesfclean
re:			fclean gamesre

# Default general rules
ALL:			lib games $(NAME)
			find . \( -name "*.cpp" -or -name "*.hpp" -or \
			-name "*.hh" -or -name "*.h" \) | etags -

CLEAN:			libclean gamesclean
			$(RM) $(OBJS) 

FCLEAN:			CLEAN clean libfclean gamesfclean
			$(RM) $(NAME) $(SFMLNAME)

RE:			FCLEAN libre gamesre ALL

# General graphical libraries rules
lib:			SFML       OPENGL       NCURSES
libclean:		SFMLclean  OPENGLclean  NCURSESclean
libfclean:		SFMLfclean OPENGLfclean NCURSESfclean
libre:			SFMLre     OPENGLre     NCURSESre

# General games rules
games:			snake       solarFox
gamesclean:		snakeclean  solarFoxclean
gamesfclean:		snakefclean solarFoxfclean
gamesre:		snakere     solarFoxre

# core rule
$(NAME):		$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS) \

# snake rules
snake:
			make        -C ./games/snake/
snakeclean:
			make clean  -C ./games/snake/
snakefclean:
			make fclean -C ./games/snake/
snakere:
			make re     -C ./games/snake/

# solarFox rules
solarFox:
			make        -C ./games/solarFox/
solarFoxclean:
			make clean  -C ./games/solarFox/
solarFoxfclean:
			make fclean -C ./games/solarFox/
solarFoxre:
			make re     -C ./games/solarFox/

# SFML rules
SFML:
			make        -C ./lib/SFML/
SFMLclean:
			make clean  -C ./lib/SFML/
SFMLfclean:
			make fclean -C ./lib/SFML/
SFMLre:
			make re     -C ./lib/SFML/
# OpenGL rules
OPENGL:
			make        -C ./lib/openGL/
OPENGLclean:
			make clean  -C ./lib/openGL/
OPENGLfclean:
			make fclean -C ./lib/openGL/
OPENGLre:
			make re     -C ./lib/openGL/

# Ncurses rules
NCURSES:
			make        -C ./lib/ncurses/
NCURSESclean:
			make clean  -C ./lib/ncurses/
NCURSESfclean:
			make fclean -C ./lib/ncurses/
NCURSESre:
			make re     -C ./lib/ncurses/

# mes noeuils, ça pique !
.PHONY:			all        re           clean         fclean  \
			ALL        RE           CLEAN         FCLEAN  \
			lib        libre        libclean      libfclean \
			games      gamesre      gamesclean    gamesfclean \
			snake      snakere      snakeclean    snakefclean \
			solarFox   solarFoxRe   solarFoxclean solarFoxfclean \
			SFML       OPENGL       NCURSES \
			SFMLclean  OPENGLclean  NCURSESclean \
			SFMLfclean OPENGLfclean NCURSESfclean \
			SFMLre     OPENGLre     NCURSESre
