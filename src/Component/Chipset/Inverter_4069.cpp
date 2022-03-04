/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Invert_4069
*/

#include "Inverter_4069.hpp"

Inverter_4069::Inverter_4069() : Component("4069", 14)
{
}

Inverter_4069::~Inverter_4069()
{
}

void Inverter_4069::simulate(std::size_t tick)
{
    AnalogicGate gate;

    UNUSED(tick);
    setSinglePin(1, gate.not_gate(_Pin[0]));
    setSinglePin(3, gate.not_gate(_Pin[2]));
    setSinglePin(5, gate.not_gate(_Pin[4]));
    setSinglePin(7, gate.not_gate(_Pin[8]));
    setSinglePin(9, gate.not_gate(_Pin[10]));
    setSinglePin(11, gate.not_gate(_Pin[12]));
}
