/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Or_4071
*/

#include "Or_4071.hpp"

Or_4071::Or_4071(std::string name) : Component("4071", 14)
{
}

Or_4071::~Or_4071()
{
}

void Or_4071::simulate(std::size_t tick)
{
    AnalogicGate gate = AnalogicGate();

    setSinglePin(3, gate.or_gate(_Pin[0], _Pin[1]));
    setSinglePin(4, gate.or_gate(_Pin[4], _Pin[5]));
    setSinglePin(10, gate.or_gate(_Pin[7], _Pin[8]));
    setSinglePin(11, gate.or_gate(_Pin[11], _Pin[12]));
}
