/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_or
*/

#include "Or_4071.hpp"
#include <criterion/criterion.h>

// MODULE 1
Test(or, false_result_1)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(0, nts::Tristate::FALSE);
    gate_or.setSinglePin(1, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(2), nts::Tristate::FALSE);
}

Test(or, true_test_1)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(0, nts::Tristate::FALSE);
    gate_or.setSinglePin(1, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(2), nts::Tristate::TRUE);
}

Test(or, undefined_test_true_1)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(0, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(2), nts::Tristate::TRUE);
}

Test(or, undefined_test_undef_1)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(1, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(2), nts::Tristate::UNDEFINED);
}

// MODULE 2
Test(or, false_result_2)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(4, nts::Tristate::FALSE);
    gate_or.setSinglePin(5, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(3), nts::Tristate::FALSE);
}

Test(or, true_test_2)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(4, nts::Tristate::FALSE);
    gate_or.setSinglePin(5, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(3), nts::Tristate::TRUE);
}

Test(or, undefined_test_true_2)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(4, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(3), nts::Tristate::TRUE);
}

Test(or, undefined_test_undef_2)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(5, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(3), nts::Tristate::UNDEFINED);
}

// MODULE 3
Test(or, false_result_3)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(7, nts::Tristate::FALSE);
    gate_or.setSinglePin(8, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(9), nts::Tristate::FALSE);
}

Test(or, true_test_3)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(7, nts::Tristate::FALSE);
    gate_or.setSinglePin(8, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(9), nts::Tristate::TRUE);
}

Test(or, undefined_test_true_3)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(7, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(9), nts::Tristate::TRUE);
}

Test(or, undefined_test_undef_3)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(8, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(9), nts::Tristate::UNDEFINED);
}

// MODULE 4
Test(or, false_result_4)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(11, nts::Tristate::FALSE);
    gate_or.setSinglePin(12, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(10), nts::Tristate::FALSE);
}

Test(or, true_test_4)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(11, nts::Tristate::FALSE);
    gate_or.setSinglePin(12, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(10), nts::Tristate::TRUE);
}

Test(or, undefined_test_true_4)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(11, nts::Tristate::TRUE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(10), nts::Tristate::TRUE);
}

Test(or, undefined_test_undef_4)
{
    Or_4071 gate_or;

    gate_or.setSinglePin(12, nts::Tristate::FALSE);
    gate_or.simulate(0);

    cr_assert_eq(gate_or.compute(10), nts::Tristate::UNDEFINED);
}