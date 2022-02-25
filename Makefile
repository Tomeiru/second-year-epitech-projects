##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/AnalogicGate.cpp	\
		src/Circuit.cpp	\
		src/CommandFunction.cpp	\
		src/NanoError.cpp	\
		src/NanoLoop.cpp	\
		src/NanoParser.cpp	\
		src/NanoTekSpice.cpp	\
		src/Component/Component.cpp	\
		src/Component/Factory.cpp	\
		src/Component/Chipset/Adder_4008.cpp	\
		src/Component/Chipset/And_4081.cpp	\
		src/Component/Chipset/Clock.cpp	\
		src/Component/Chipset/Counter_4040.cpp	\
		src/Component/Chipset/Decoder_4514.cpp	\
		src/Component/Chipset/False.cpp	\
		src/Component/Chipset/FlipFlop_4013.cpp	\
		src/Component/Chipset/Input.cpp	\
		src/Component/Chipset/Inverter_4069.cpp	\
		src/Component/Chipset/Johnson_4017.cpp	\
		src/Component/Chipset/Nand_4011.cpp	\
		src/Component/Chipset/Nor_4001.cpp	\
		src/Component/Chipset/Or_4071.cpp	\
		src/Component/Chipset/Output.cpp	\
		src/Component/Chipset/RAM_4801.cpp	\
		src/Component/Chipset/Register_4094.cpp	\
		src/Component/Chipset/ROM_2716.cpp	\
		src/Component/Chipset/Selector_4512.cpp	\
		src/Component/Chipset/True.cpp	\
		src/Component/Chipset/Xor_4030.cpp

NAME =	nanotekspice

OBJ = 	$(SRC:.cpp=.o)

CPPFLAGS = -g -I./include -I./include/Component -I./include/Component/Chipset -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
