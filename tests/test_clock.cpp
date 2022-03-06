/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_clock
*/

#include "Clock.hpp"
#include <criterion/criterion.h>

Test(clock, test_basic_clock)
{
    Clock clock;

    clock.setSinglePin(0, nts::Tristate::FALSE);
    cr_expect_eq(clock.compute(0), nts::Tristate::FALSE);
    clock.simulate(0);
    cr_expect_eq(clock.compute(0), nts::Tristate::TRUE);
    clock.simulate(0);
    cr_expect_eq(clock.compute(0), nts::Tristate::FALSE);
    clock.simulate(0);
    cr_expect_eq(clock.compute(0), nts::Tristate::TRUE);
}