/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Nor_4001
*/

#include "Nor_4001.hpp"

Nor_4001::Nor_4001(std::string name) : Component("4001", 14)
{
}

Nor_4001::~Nor_4001()
{
}

void Nor_4001::simulate(std::size_t tick)
{
    AnalogicGate gate = AnalogicGate();

    UNUSED(tick);
    setSinglePin(3, gate.nor_gate(_Pin[0], _Pin[1]));
    setSinglePin(4, gate.nor_gate(_Pin[4], _Pin[5]));
    setSinglePin(10, gate.nor_gate(_Pin[7], _Pin[8]));
    setSinglePin(11, gate.nor_gate(_Pin[11], _Pin[12]));
}
