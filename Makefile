##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/memcpy.asm	\
		sources/memmove.asm	\
		sources/memset.asm	\
		sources/strcasecmp.asm	\
		sources/strchr.asm	\
		sources/strcmp.asm	\
		sources/strcspn.asm	\
		sources/strlen.asm	\
		sources/strncmp.asm	\
		sources/strpbrk.asm	\
		sources/strrchr.asm	\
		sources/strstr.asm

CFLAGS = -Wall -Wextra -fpic -I./include

OBJ = $(SRC:.asm=.o)

NAME = libasm.so

%.o:	%.asm
		nasm -f elf64 $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
		ld -shared -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
