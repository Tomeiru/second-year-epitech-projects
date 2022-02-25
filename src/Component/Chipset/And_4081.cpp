/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** And_4081
*/

#include "And_4081.hpp"

And_4081::And_4081(std::string name) : Component("4081", 14)
{
}

And_4081::~And_4081()
{
}

void And_4081::simulate(std::size_t tick)
{
    AnalogicGate gate = AnalogicGate();

    setSinglePin(3, gate.and_gate(_Pin[0], _Pin[1]));
    setSinglePin(4, gate.and_gate(_Pin[4], _Pin[5]));
    setSinglePin(10, gate.and_gate(_Pin[7], _Pin[8]));
    setSinglePin(11, gate.and_gate(_Pin[11], _Pin[12]));
}
