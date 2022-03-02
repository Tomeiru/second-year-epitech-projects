/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Register_4096
*/

#include "Register_4094.hpp"

Register_4094::Register_4094() : Component("4094", 16)
{
}

Register_4094::~Register_4094()
{
}

/*
S = 1, D = 2, Cl = 3
Q1 = 4, Q2 = 5, Q3 = 6, Q4 = 7
Q5 = 14, Q6 = 13, Q7 = 12, Q8 = 11
Q's = 10, Qs = 9
Out = 15

*/

void Register_4094::simulate(std::size_t tick)
{
    AnalogicGate gate = AnalogicGate();
    nts::Tristate tmp = _Pin[2];

    UNUSED(tick);
    if (_Pin[14] == nts::Tristate::FALSE) {
        setAllPin(nts::Tristate::UNDEFINED);
        setSinglePin(2, tmp);
        setSinglePin(14, nts::Tristate::FALSE);
        return;
    }
    if (_Pin[2] == nts::Tristate::FALSE) {
        setSinglePin(9, _Pin[11]);
        return;
    }
    if (_Pin[0] == nts::Tristate::FALSE) {
        setSinglePin(8, _Pin[11]);
        return;
    }
    setSinglePin(10, _Pin[11]);
    setSinglePin(9, _Pin[11]);
    setSinglePin(11, _Pin[12]);
    setSinglePin(12, _Pin[13]);
    setSinglePin(13, _Pin[6]);
    setSinglePin(6, _Pin[5]);
    setSinglePin(5, _Pin[4]);
    setSinglePin(4, _Pin[3]);
    setSinglePin(3, _Pin[1]);
}
