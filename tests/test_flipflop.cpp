/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_flipflop
*/

#include "FlipFlop_4013.hpp"
#include <criterion/criterion.h>

// MODULE 1
Test(flipflop, reset_test_1)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(2, nts::Tristate::FALSE);
    flip.setSinglePin(3, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(0), nts::Tristate::FALSE);
    cr_assert_eq(flip.compute(1), nts::Tristate::TRUE);
}

Test(flipflop, set_test_1)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(2, nts::Tristate::FALSE);
    flip.setSinglePin(5, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(0), nts::Tristate::TRUE);
    cr_assert_eq(flip.compute(1), nts::Tristate::FALSE);
}

Test(flipflop, reset_set_test_1)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(2, nts::Tristate::FALSE);
    flip.setSinglePin(3, nts::Tristate::TRUE);
    flip.setSinglePin(5, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(0), nts::Tristate::TRUE);
    cr_assert_eq(flip.compute(1), nts::Tristate::TRUE);
}

Test(flipflop, clock_negative_edge_1)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(2, nts::Tristate::FALSE);
    flip.setSinglePin(4, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(0), nts::Tristate::UNDEFINED);
    cr_assert_eq(flip.compute(1), nts::Tristate::UNDEFINED);
}

Test(flipflop, data_to_one_1)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(2, nts::Tristate::TRUE);
    flip.setSinglePin(4, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(0), nts::Tristate::TRUE);
    cr_assert_eq(flip.compute(1), nts::Tristate::FALSE);
}

Test(flipflop, data_to_zero_1)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(2, nts::Tristate::TRUE);
    flip.setSinglePin(4, nts::Tristate::FALSE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(0), nts::Tristate::FALSE);
    cr_assert_eq(flip.compute(1), nts::Tristate::TRUE);
}

// MODULE 2

Test(flipflop, reset_test_2)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(10, nts::Tristate::FALSE);
    flip.setSinglePin(9, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(12), nts::Tristate::FALSE);
    cr_assert_eq(flip.compute(11), nts::Tristate::TRUE);
}

Test(flipflop, set_test_2)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(10, nts::Tristate::FALSE);
    flip.setSinglePin(7, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(12), nts::Tristate::TRUE);
    cr_assert_eq(flip.compute(11), nts::Tristate::FALSE);
}

Test(flipflop, reset_set_test_2)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(10, nts::Tristate::FALSE);
    flip.setSinglePin(9, nts::Tristate::TRUE);
    flip.setSinglePin(7, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(12), nts::Tristate::TRUE);
    cr_assert_eq(flip.compute(11), nts::Tristate::TRUE);
}


Test(flipflop, clock_negative_edge_2)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(10, nts::Tristate::FALSE);
    flip.setSinglePin(8, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(12), nts::Tristate::UNDEFINED);
    cr_assert_eq(flip.compute(11), nts::Tristate::UNDEFINED);
}

Test(flipflop, data_to_one_2)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(10, nts::Tristate::TRUE);
    flip.setSinglePin(8, nts::Tristate::TRUE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(12), nts::Tristate::TRUE);
    cr_assert_eq(flip.compute(11), nts::Tristate::FALSE);
}

Test(flipflop, data_to_zero_2)
{
    FlipFlop_4013 flip;

    flip.setSinglePin(10, nts::Tristate::TRUE);
    flip.setSinglePin(8, nts::Tristate::FALSE);
    flip.simulate(0);

    cr_expect_eq(flip.compute(12), nts::Tristate::FALSE);
    cr_assert_eq(flip.compute(11), nts::Tristate::TRUE);
}