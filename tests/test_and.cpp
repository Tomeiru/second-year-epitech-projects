/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_and
*/

#include "And_4081.hpp"
#include <criterion/criterion.h>

// MODULE 1
Test(and, false_result_1)
{
    And_4081 gate_and;

    gate_and.setSinglePin(0, nts::Tristate::FALSE);
    gate_and.setSinglePin(1, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(2), nts::Tristate::FALSE);
}

Test(and, true_test_1)
{
    And_4081 gate_and;

    gate_and.setSinglePin(0, nts::Tristate::TRUE);
    gate_and.setSinglePin(1, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(2), nts::Tristate::TRUE);
}

Test(and, undefined_test_false_1)
{
    And_4081 gate_and;

    gate_and.setSinglePin(0, nts::Tristate::FALSE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(2), nts::Tristate::FALSE);
}

Test(and, undefined_test_undef_1)
{
    And_4081 gate_and;

    gate_and.setSinglePin(1, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(2), nts::Tristate::UNDEFINED);
}

// MODULE 2
Test(and, false_result_2)
{
    And_4081 gate_and;

    gate_and.setSinglePin(4, nts::Tristate::FALSE);
    gate_and.setSinglePin(5, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(3), nts::Tristate::FALSE);
}

Test(and, true_test_2)
{
    And_4081 gate_and;

    gate_and.setSinglePin(4, nts::Tristate::TRUE);
    gate_and.setSinglePin(5, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(3), nts::Tristate::TRUE);
}

Test(and, undefined_test_false_2)
{
    And_4081 gate_and;

    gate_and.setSinglePin(4, nts::Tristate::FALSE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(3), nts::Tristate::FALSE);
}

Test(and, undefined_test_undef_2)
{
    And_4081 gate_and;

    gate_and.setSinglePin(5, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(3), nts::Tristate::UNDEFINED);
}

// MODULE 3
Test(and, false_result_3)
{
    And_4081 gate_and;

    gate_and.setSinglePin(7, nts::Tristate::FALSE);
    gate_and.setSinglePin(8, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(9), nts::Tristate::FALSE);
}

Test(and, true_test_3)
{
    And_4081 gate_and;

    gate_and.setSinglePin(7, nts::Tristate::TRUE);
    gate_and.setSinglePin(8, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(9), nts::Tristate::TRUE);
}

Test(and, undefined_test_false_3)
{
    And_4081 gate_and;

    gate_and.setSinglePin(7, nts::Tristate::FALSE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(9), nts::Tristate::FALSE);
}

Test(and, undefined_test_undef_3)
{
    And_4081 gate_and;

    gate_and.setSinglePin(8, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(9), nts::Tristate::UNDEFINED);
}

// MODULE 4
Test(and, false_result_4)
{
    And_4081 gate_and;

    gate_and.setSinglePin(11, nts::Tristate::FALSE);
    gate_and.setSinglePin(12, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(10), nts::Tristate::FALSE);
}

Test(and, true_test_4)
{
    And_4081 gate_and;

    gate_and.setSinglePin(11, nts::Tristate::TRUE);
    gate_and.setSinglePin(12, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(10), nts::Tristate::TRUE);
}

Test(and, undefined_test_false_4)
{
    And_4081 gate_and;

    gate_and.setSinglePin(11, nts::Tristate::FALSE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(10), nts::Tristate::FALSE);
}

Test(and, undefined_test_undef_4)
{
    And_4081 gate_and;

    gate_and.setSinglePin(12, nts::Tristate::TRUE);
    gate_and.simulate(0);

    cr_assert_eq(gate_and.compute(10), nts::Tristate::UNDEFINED);
}