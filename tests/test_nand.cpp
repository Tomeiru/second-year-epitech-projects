/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_nand
*/

#include "Nand_4011.hpp"
#include <criterion/criterion.h>

// MODULE 1
Test(nand, false_result_1)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(0, nts::Tristate::FALSE);
    gate_nand.setSinglePin(1, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(2), nts::Tristate::TRUE);
}

Test(nand, true_test_1)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(0, nts::Tristate::TRUE);
    gate_nand.setSinglePin(1, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(2), nts::Tristate::FALSE);
}

Test(nand, undefined_test_false_1)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(0, nts::Tristate::FALSE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(2), nts::Tristate::TRUE);
}

Test(nand, undefined_test_undef_1)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(1, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(2), nts::Tristate::UNDEFINED);
}

// MODULE 2
Test(nand, false_result_2)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(4, nts::Tristate::FALSE);
    gate_nand.setSinglePin(5, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(3), nts::Tristate::TRUE);
}

Test(nand, true_test_2)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(4, nts::Tristate::TRUE);
    gate_nand.setSinglePin(5, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(3), nts::Tristate::FALSE);
}

Test(nand, undefined_test_false_2)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(4, nts::Tristate::FALSE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(3), nts::Tristate::TRUE);
}

Test(nand, undefined_test_undef_2)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(5, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(3), nts::Tristate::UNDEFINED);
}

// MODULE 3
Test(nand, false_result_3)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(7, nts::Tristate::FALSE);
    gate_nand.setSinglePin(8, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(9), nts::Tristate::TRUE);
}

Test(nand, true_test_3)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(7, nts::Tristate::TRUE);
    gate_nand.setSinglePin(8, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(9), nts::Tristate::FALSE);
}

Test(nand, undefined_test_false_3)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(7, nts::Tristate::FALSE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(9), nts::Tristate::TRUE);
}

Test(nand, undefined_test_undef_3)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(8, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(9), nts::Tristate::UNDEFINED);
}

// MODULE 4
Test(nand, false_result_4)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(11, nts::Tristate::FALSE);
    gate_nand.setSinglePin(12, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(10), nts::Tristate::TRUE);
}

Test(nand, true_test_4)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(11, nts::Tristate::TRUE);
    gate_nand.setSinglePin(12, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(10), nts::Tristate::FALSE);
}

Test(nand, undefined_test_false_4)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(11, nts::Tristate::FALSE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(10), nts::Tristate::TRUE);
}

Test(nand, undefined_test_undef_4)
{
    Nand_4011 gate_nand;

    gate_nand.setSinglePin(12, nts::Tristate::TRUE);
    gate_nand.simulate(0);

    cr_assert_eq(gate_nand.compute(10), nts::Tristate::UNDEFINED);
}