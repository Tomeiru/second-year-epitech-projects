/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_xor
*/

#include "Xor_4030.hpp"
#include <criterion/criterion.h>

// MODULE 1
Test(xor, false_result_1)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(0, nts::Tristate::FALSE);
    gate_xor.setSinglePin(1, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(2), nts::Tristate::FALSE);
}

Test(xor, other_false_result_1)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(0, nts::Tristate::TRUE);
    gate_xor.setSinglePin(1, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(2), nts::Tristate::FALSE);
}

Test(xor, true_test_1)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(0, nts::Tristate::FALSE);
    gate_xor.setSinglePin(1, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(2), nts::Tristate::TRUE);
}

Test(xor, undefined_test_1)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(1, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(2), nts::Tristate::UNDEFINED);
}

// MODULE 2
Test(xor, false_result_2)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(4, nts::Tristate::FALSE);
    gate_xor.setSinglePin(5, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(3), nts::Tristate::FALSE);
}

Test(xor, other_false_result_2)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(4, nts::Tristate::TRUE);
    gate_xor.setSinglePin(5, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(3), nts::Tristate::FALSE);
}

Test(xor, true_test_2)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(4, nts::Tristate::FALSE);
    gate_xor.setSinglePin(5, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(3), nts::Tristate::TRUE);
}

Test(xor, undefined_test_undef_2)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(5, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(3), nts::Tristate::UNDEFINED);
}

// MODULE 3
Test(xor, false_result_3)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(7, nts::Tristate::FALSE);
    gate_xor.setSinglePin(8, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(9), nts::Tristate::FALSE);
}

Test(xor, other_false_result_3)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(7, nts::Tristate::TRUE);
    gate_xor.setSinglePin(8, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(9), nts::Tristate::FALSE);
}

Test(xor, true_test_3)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(7, nts::Tristate::FALSE);
    gate_xor.setSinglePin(8, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(9), nts::Tristate::TRUE);
}

Test(xor, undefined_test_undef_3)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(8, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(9), nts::Tristate::UNDEFINED);
}

// MODULE 4
Test(xor, false_result_4)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(11, nts::Tristate::FALSE);
    gate_xor.setSinglePin(12, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(10), nts::Tristate::FALSE);
}

Test(xor, other_false_result_4)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(11, nts::Tristate::TRUE);
    gate_xor.setSinglePin(12, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(10), nts::Tristate::FALSE);
}

Test(xor, true_test_4)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(11, nts::Tristate::FALSE);
    gate_xor.setSinglePin(12, nts::Tristate::TRUE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(10), nts::Tristate::TRUE);
}

Test(xor, undefined_test_undef_4)
{
    Xor_4030 gate_xor;

    gate_xor.setSinglePin(12, nts::Tristate::FALSE);
    gate_xor.simulate(0);

    cr_assert_eq(gate_xor.compute(10), nts::Tristate::UNDEFINED);
}