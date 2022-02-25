/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** FlipFlop_4013
*/

#include "FlipFlop_4013.hpp"

FlipFlop_4013::FlipFlop_4013(std::string name) : Component("4013", 14)
{
}

FlipFlop_4013::~FlipFlop_4013()
{
}

// Q1 = 1, /Q1 = 2
// Cl1 = 3, R1 = 4
// D1 = 5, S1 = 6

// Q2 = 13, /Q2 = 12
// Cl2 = 11, R2 = 10
// D2 = 9, S2 = 8

void FlipFlop_4013::simulate(std::size_t tick)
{
    AnalogicGate gate = AnalogicGate();

    if (_Pin[3] == nts::Tristate::TRUE && _Pin[5] == nts::Tristate::TRUE) {
        setSinglePin(0, nts::Tristate::TRUE);
        setSinglePin(1, nts::Tristate::TRUE);
    } else if (_Pin[3] == nts::Tristate::TRUE)
        setSinglePin(1, nts::Tristate::TRUE);
    else if (_Pin[5] == nts::Tristate::TRUE)
        setSinglePin(0, nts::Tristate::TRUE);
}