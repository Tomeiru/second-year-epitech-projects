/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Counter_4040
*/

#include "Counter_4040.hpp"

Counter_4040::Counter_4040() : Component("4040", 16)
{
}

Counter_4040::~Counter_4040()
{
}

/*
Q1 = 9, Q2 = 7, Q3 = 6, Q4 = 5
Q5 = 3, Q6 = 2, Q7 = 4, Q8 = 13
Q9 = 12, Q10 = 14, Q11 = 15, Q12 = 1
R = 11, C = 10
*/

void Counter_4040::simulate(std::size_t tick)
{
    std::string binaire;
    nts::Tristate tmp = _Pin[9];

    if (_Pin[10] == nts::Tristate::TRUE) {
        setAllPin(nts::Tristate::FALSE);
        setSinglePin(9, tmp);
        return;
    }
    tick = tick % 4096;
    while(tick!=0) {
        binaire = (tick % 2 == 0 ? "0" : "1") + binaire;
        tick /= 2;
    }
    binaire = std::string((size_t)12 - std::min((size_t)12, binaire.length()), '0') + binaire;
    if (_Pin[9] == nts::Tristate::FALSE) {
        setSinglePin(8, binaire[11] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(6, binaire[10] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(5, binaire[9] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(4, binaire[8] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(2, binaire[7] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(1, binaire[6] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(3, binaire[5] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(12, binaire[4] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(11, binaire[3] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(13, binaire[2] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(14, binaire[1] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(0, binaire[0] == '1' ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    }
}