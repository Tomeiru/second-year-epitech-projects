/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock() : Component("Clock", 1)
{
}

Clock::~Clock()
{
}

void Clock::simulate(std::size_t tick)
{
    UNUSED(tick);
    if (_Pin[0] == nts::Tristate::NEWTRUE) {
        return (setSinglePin(0, nts::TRUE));
    }
    if (_Pin[0] == nts::NEWFALSE) {
        return (setSinglePin(0, nts::FALSE));
    }
    if (_Pin[0] == nts::Tristate::TRUE) {
        setSinglePin(0, nts::Tristate::FALSE);
    }
    else if (_Pin[0] == nts::Tristate::FALSE) {
        setSinglePin(0, nts::Tristate::TRUE);
    }
}