/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** AnalogicGate
*/

#include "AnalogicGate.hpp"

AnalogicGate::AnalogicGate()
{
}

AnalogicGate::~AnalogicGate()
{
}

nts::Tristate not_gate(nts::Tristate a)
{
    if (a == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return ((a == nts::Tristate::TRUE) ? nts::Tristate::FALSE : nts::Tristate::TRUE);
}

nts::Tristate and_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::FALSE || b == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    else if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::TRUE);
}


nts::Tristate or_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    else if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    return (nts::Tristate::UNDEFINED);
}

nts::Tristate nand_gate(nts::Tristate a, nts::Tristate b)
{
    return (not_gate(and_gate(a, b)));
}

nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b)
{
    return (not_gate(or_gate(a, b)));
}

nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::TRUE);
    else if (a == b)
        return (nts::Tristate::FALSE);
    return (nts::Tristate::TRUE);
}
