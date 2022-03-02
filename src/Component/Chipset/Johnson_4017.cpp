/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Johnson_4017
*/

#include "Johnson_4017.hpp"

Johnson_4017::Johnson_4017() : Component("4017", 15)
{
}

Johnson_4017::~Johnson_4017()
{
}

// Q0 = 3, Q1 = 2, Q2 = 4, Q3 = 7
// Q4 = 10, Q5 = 1, Q6 = 5, Q7 = 6
// Q8 = 9, Q9 = 11, Q5-9 = 12
// Cl = 14, /CL = 13, MR = 15

void Johnson_4017::simulate(std::size_t tick)
{
    AnalogicGate gate;
    nts::Tristate clock = gate.and_gate(_Pin[13], gate.not_gate(_Pin[12]));

    tick %= 10;
    if (_Pin[15] == nts::Tristate::TRUE) {
        setAllPin(nts::Tristate::FALSE);
        setSinglePin(11, nts::Tristate::TRUE);
        setSinglePin(2, nts::Tristate::TRUE);
        return;
    }
    if (clock == nts::Tristate::TRUE) {
        setSinglePin(2, tick == 0 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(1, tick == 1 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(3, tick == 2 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(6, tick == 3 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(9, tick == 4 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(0, tick == 5 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(4, tick == 6 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(5, tick == 7 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(8, tick == 8 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(10, tick == 9 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
        setSinglePin(11, tick < 6 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    }
}