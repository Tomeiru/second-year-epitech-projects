/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Adder_4008
*/

#include "Adder_4008.hpp"

Adder_4008::Adder_4008(std::string name) : Component(name, 16)
{
}

Adder_4008::~Adder_4008()
{
}

// A1 = 7, B1 = 6
// A2 = 5, B2 = 4
// A3 = 3, B3 = 2
// A4 = 1, B4 = 15
// Cin = 9, Cout = 14
// S1 = 10, S2 = 11, S3 = 12, S4 = 13

void Adder_4008::simulate(std::size_t tick)
{
    AnalogicGate gate = AnalogicGate();

    nts::Tristate next_A4 = gate.or_gate(_Pin[0], _Pin[14]);
    nts::Tristate next_B4 = gate.and_gate(_Pin[14], _Pin[0]);
    nts::Tristate next_A3 = gate.or_gate(_Pin[2], _Pin[1]);
    nts::Tristate next_B3 = gate.and_gate(_Pin[1], _Pin[2]);
    nts::Tristate next_A2 = gate.or_gate(_Pin[4], _Pin[3]);
    nts::Tristate next_B2 = gate.and_gate(_Pin[3], _Pin[4]);
    nts::Tristate next_A1 = gate.or_gate(_Pin[6], _Pin[5]);
    nts::Tristate next_B1 = gate.and_gate(_Pin[5], _Pin[6]);
    nts::Tristate rest_1 = gate.or_gate(gate.and_gate(next_A1, _Pin[8]), next_B1);
    nts::Tristate rest_2 = gate.or_gate(gate.and_gate(next_A2, rest_1), next_B2);
    nts::Tristate rest_3 = gate.or_gate(gate.and_gate(next_A3, rest_2), next_B3);
    nts::Tristate quadra_and1 = gate.and_gate(gate.and_gate(next_A4, next_A3), gate.and_gate(next_A2, next_A1));
    nts::Tristate quadra_and2 = gate.and_gate(gate.and_gate(next_A4, next_A3), gate.and_gate(next_A2, next_B1));
    nts::Tristate trio = gate.and_gate(next_A1, gate.and_gate(next_A3, next_B2));
    nts::Tristate quadra_or = gate.or_gate(gate.or_gate(next_B1, gate.and_gate(next_A4, next_B3)), gate.or_gate(trio, quadra_and2));

    setSinglePin(12, gate.not_gate(gate.xor_gate(gate.or_gate(next_B4, gate.not_gate(next_A4)), rest_3)));
    setSinglePin(11, gate.not_gate(gate.xor_gate(gate.or_gate(next_B3, gate.not_gate(next_A3)), rest_2)));
    setSinglePin(10, gate.not_gate(gate.xor_gate(gate.or_gate(next_B2, gate.not_gate(next_A2)), rest_1)));
    setSinglePin(9, gate.not_gate(gate.xor_gate(gate.or_gate(next_B1, gate.not_gate(next_A1)), _Pin[8])));
    setSinglePin(13, gate.or_gate(gate.and_gate(_Pin[8], quadra_and1), quadra_or));
}