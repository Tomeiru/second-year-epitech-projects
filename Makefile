##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/main.cpp	\
		src/argumentCheck.cpp	\
		src/MyGKrellmInfo.cpp	\
		src/Modules/DefaultModule.cpp	\
		src/Modules/DateTimeModule.cpp	\
		src/Modules/HostUserNameModule.cpp	\
		src/Modules/OSKernelVersionModule.cpp	\
		src/Modules/HelpModule.cpp	\
		src/nCurses.cpp	\
		src/sfml.cpp

NAME =	MyGKrellm

OBJ = 	$(SRC:.cpp=.o)

CPPFLAGS = -I./includes -I./includes/Modules -g -Wall -Wextra -lncurses -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
