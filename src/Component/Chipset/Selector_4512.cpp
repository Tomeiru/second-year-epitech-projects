/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Selector_4512
*/

#include "Selector_4512.hpp"

Selector_4512::Selector_4512() : Component("4512", 16)
{
}

Selector_4512::~Selector_4512()
{
}

/*
X0 = 1, X1 = 2, X2 = 3, X3 = 4
X4 = 5, X5 = 6, X6 = 7, X7 = 9
OE = 15, Z = 14, I = 10
A = 11, B = 12, C = 13
*/

void Selector_4512::simulate(std::size_t tick)
{
    int addr = 0;

    UNUSED(tick);
    if (_Pin[9] == nts::UNDEFINED || _Pin[14] == nts::UNDEFINED) {
        setSinglePin(13, nts::Tristate::UNDEFINED);
        return;
    }
    if (_Pin[14] == nts::Tristate::TRUE) {
        setSinglePin(13, nts::Tristate::UNDEFINED);
        return;
    } else if (_Pin[9] == nts::Tristate::TRUE) {
        setSinglePin(13, nts::Tristate::FALSE);
        return;
    }
    addr += _Pin[10] == nts::Tristate::TRUE ? 1 : 0;
    addr += _Pin[11] == nts::Tristate::TRUE ? 2 : 0;
    addr += _Pin[12] == nts::Tristate::TRUE ? 4 : 0;
    addr += addr == 7 ? 1 : 0;
    setSinglePin(13, _Pin[addr]);
}
