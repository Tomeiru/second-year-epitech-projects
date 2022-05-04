##
## EPITECH PROJECT, 2022
## B-FUN-400-STG-4-1-wolfram-tom.laumonier
## File description:
## Makefile
##

NAME =	imageCompressor

BINARY_PATH	:=	$(shell stack path --local-install-root)

all:
	stack build
	cp "$(BINARY_PATH)/bin/$(NAME)-exe" ./$(NAME)

clean:
	stack clean

fclean: clean
		rm -f $(NAME)

re: 	 all

.PHONY: all clean fclean re