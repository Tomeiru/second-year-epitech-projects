##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/main.cpp	\
		src/argumentCheck.cpp	\
		src/MyGKrellmInfo.cpp	\
		src/Modules/DateTimeModule.cpp	\
		src/Modules/HostnameModule.cpp	\
		src/Modules/KernelVersionModule.cpp	\
		src/Modules/OSModule.cpp	\
		src/Modules/UsernameModule.cpp

NAME =	MyGKrellm

OBJ = 	$(SRC:.cpp=.o)

CPPFLAGS = -I./includes -I./includes/Modules -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
