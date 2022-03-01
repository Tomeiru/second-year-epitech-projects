/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Decoder_4514
*/

#include "Decoder_4514.hpp"

Decoder_4514::Decoder_4514(std::string name) : Component("4514", 24)
{
}

Decoder_4514::~Decoder_4514()
{
}

/*
X0 = 11, X1 = 9, X2 = 10, X3 = 8
X4 = 7, X5 = 6, X6 = 5, X7 = 4
X8 = 18, X9 = 17, X10 = 20, X11 = 19
X12 = 14, X13 = 13, X14 = 16, X15 = 15st
S = 1, I = 23
A = 2, B = 3, C = 21, D = 22
*/

void Decoder_4514::simulate(std::size_t tick)
{
    int addr = 0;

    if (_Pin[22] == nts::Tristate::TRUE) {
        setAllPin(nts::Tristate::FALSE);
        setSinglePin(21, nts::Tristate::TRUE);
    }
    addr += _Pin[1] == nts::Tristate::TRUE ? 1 : 0;
    addr += _Pin[2] == nts::Tristate::TRUE ? 2 : 0;
    addr += _Pin[20] == nts::Tristate::TRUE ? 4 : 0;
    addr += _Pin[21] == nts::Tristate::TRUE ? 8 : 0;
    setSinglePin(10, addr == 0 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(8, addr == 1 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(9, addr == 2 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(7, addr == 3 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(6, addr == 4 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(5, addr == 5 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(4, addr == 6 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(3, addr == 7 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(17, addr == 8 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(16, addr == 9 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(19, addr == 10 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(18, addr == 11 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(13, addr == 12 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(12, addr == 13 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(15, addr == 14 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    setSinglePin(14, addr == 15 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
}