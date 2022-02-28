/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Nand_4011
*/

#include "Nand_4011.hpp"

Nand_4011::Nand_4011() : Component("4011", 14)
{
}

Nand_4011::~Nand_4011()
{
}

void Nand_4011::simulate(std::size_t tick)
{
    AnalogicGate gate;

    setSinglePin(2, gate.nand_gate(_Pin[0], _Pin[1]));
    setSinglePin(3, gate.nand_gate(_Pin[4], _Pin[5]));
    setSinglePin(9, gate.nand_gate(_Pin[7], _Pin[8]));
    setSinglePin(10, gate.nand_gate(_Pin[11], _Pin[12]));
}
