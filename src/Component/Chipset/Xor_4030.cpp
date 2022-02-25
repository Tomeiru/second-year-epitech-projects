/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Xor_4030
*/

#include "Xor_4030.hpp"

Xor_4030::Xor_4030(std::string name) : Component("4030", 14)
{
}

Xor_4030::~Xor_4030()
{
}

void Xor_4030::simulate(std::size_t tick)
{
    AnalogicGate gate = AnalogicGate();

    setSinglePin(3, gate.xor_gate(_Pin[0], _Pin[1]));
    setSinglePin(4, gate.xor_gate(_Pin[4], _Pin[5]));
    setSinglePin(10, gate.xor_gate(_Pin[7], _Pin[8]));
    setSinglePin(11, gate.xor_gate(_Pin[11], _Pin[12]));
}
