##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME = do_it

NM = $(MAKE)	-s	-C	nm/

OBJDUMP = $(MAKE)	-s	-C	objdump/

all:	nm	objdump

nm:
		$(NM)	re

objdump:
		$(OBJDUMP)	re

clean:
		@$(NM)	clean
		@$(OBJDUMP)	clean

fclean:	clean
		@$(NM)	fclean
		@$(OBJDUMP)	fclean

re:	fclean all

.PHONY:	all	nm	objdump	clean	fclean	re