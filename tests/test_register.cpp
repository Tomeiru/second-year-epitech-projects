/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_register
*/

#include "Register_4094.hpp"
#include <criterion/criterion.h>

Test(shift, oe_button)
{
    Register_4094 shift;

    shift.setSinglePin(14, nts::Tristate::FALSE);
    shift.setSinglePin(2, nts::Tristate::TRUE);
    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(4), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(5), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(6), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(13), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(12), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(11), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(2), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(14), nts::Tristate::FALSE);
}

Test(shift, strobe)
{
    Register_4094 shift;

    shift.setSinglePin(14, nts::Tristate::TRUE);
    shift.setSinglePin(2, nts::Tristate::TRUE);
    shift.setSinglePin(0, nts::Tristate::FALSE);
    shift.setSinglePin(1, nts::Tristate::FALSE);

    shift.setSinglePin(3, nts::Tristate::TRUE);
    shift.setSinglePin(4, nts::Tristate::FALSE);
    shift.setSinglePin(5, nts::Tristate::TRUE);
    shift.setSinglePin(6, nts::Tristate::FALSE);
    shift.setSinglePin(13, nts::Tristate::FALSE);
    shift.setSinglePin(12, nts::Tristate::TRUE);
    shift.setSinglePin(11, nts::Tristate::TRUE);
    shift.setSinglePin(10, nts::Tristate::TRUE);
    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(13), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(12), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(11), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(10), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(2), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(14), nts::Tristate::TRUE);
}

Test(shift, classic_use)
{
    Register_4094 shift;
    shift.setSinglePin(14, nts::Tristate::TRUE);
    shift.setSinglePin(2, nts::Tristate::TRUE);
    shift.setSinglePin(0, nts::Tristate::TRUE);
    shift.setSinglePin(1, nts::Tristate::FALSE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(4), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(5), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(6), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(13), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(12), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(11), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::FALSE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(5), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(6), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(13), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(12), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(11), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(6), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(13), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(12), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(11), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(13), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(12), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(11), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(13), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(12), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(11), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(6), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(13), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(12), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(11), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(6), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(13), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(12), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(11), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(10), nts::Tristate::UNDEFINED);

    cr_expect_eq(shift.compute(9), nts::Tristate::UNDEFINED);
    cr_expect_eq(shift.compute(8), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(6), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(13), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(12), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(11), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(10), nts::Tristate::FALSE);

    cr_expect_eq(shift.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(8), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);

    shift.simulate(0);
    cr_expect_eq(shift.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(4), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(6), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(13), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(12), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(11), nts::Tristate::TRUE);
    cr_expect_eq(shift.compute(10), nts::Tristate::FALSE);

    cr_expect_eq(shift.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(shift.compute(8), nts::Tristate::UNDEFINED);
    shift.setSinglePin(1, nts::Tristate::TRUE);
}