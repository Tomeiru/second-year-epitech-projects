/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_nor
*/

#include "Nor_4001.hpp"
#include <criterion/criterion.h>

// MODULE 1
Test(nor, false_result_1)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(0, nts::Tristate::FALSE);
    gate_nor.setSinglePin(1, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(2), nts::Tristate::TRUE);
}

Test(nor, true_test_1)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(0, nts::Tristate::FALSE);
    gate_nor.setSinglePin(1, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(2), nts::Tristate::FALSE);
}

Test(nor, undefined_test_true_1)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(0, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(2), nts::Tristate::FALSE);
}

Test(nor, undefined_test_undef_1)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(1, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(2), nts::Tristate::UNDEFINED);
}

// MODULE 2
Test(nor, false_result_2)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(4, nts::Tristate::FALSE);
    gate_nor.setSinglePin(5, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(3), nts::Tristate::TRUE);
}

Test(nor, true_test_2)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(4, nts::Tristate::FALSE);
    gate_nor.setSinglePin(5, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(3), nts::Tristate::FALSE);
}

Test(nor, undefined_test_true_2)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(4, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(3), nts::Tristate::FALSE);
}

Test(nor, undefined_test_undef_2)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(5, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(3), nts::Tristate::UNDEFINED);
}

// MODULE 3
Test(nor, false_result_3)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(7, nts::Tristate::FALSE);
    gate_nor.setSinglePin(8, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(9), nts::Tristate::TRUE);
}

Test(nor, true_test_3)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(7, nts::Tristate::FALSE);
    gate_nor.setSinglePin(8, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(9), nts::Tristate::FALSE);
}

Test(nor, undefined_test_true_3)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(7, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(9), nts::Tristate::FALSE);
}

Test(nor, undefined_test_undef_3)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(8, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(9), nts::Tristate::UNDEFINED);
}

// MODULE 4
Test(nor, false_result_4)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(11, nts::Tristate::FALSE);
    gate_nor.setSinglePin(12, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(10), nts::Tristate::TRUE);
}

Test(nor, true_test_4)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(11, nts::Tristate::FALSE);
    gate_nor.setSinglePin(12, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(10), nts::Tristate::FALSE);
}

Test(nor, undefined_test_true_4)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(11, nts::Tristate::TRUE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(10), nts::Tristate::FALSE);
}

Test(nor, undefined_test_undef_4)
{
    Nor_4001 gate_nor;

    gate_nor.setSinglePin(12, nts::Tristate::FALSE);
    gate_nor.simulate(0);

    cr_assert_eq(gate_nor.compute(10), nts::Tristate::UNDEFINED);
}