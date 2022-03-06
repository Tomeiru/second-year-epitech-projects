/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_inverter
*/

#include "Inverter_4069.hpp"
#include <criterion/criterion.h>

// MODULE 1
Test(inverter, false_result_1)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(0, nts::Tristate::TRUE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(1), nts::Tristate::FALSE);
}

Test(inverter, true_test_1)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(0, nts::Tristate::FALSE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(1), nts::Tristate::TRUE);
}

Test(inverter, undefined_test_1)
{
    Inverter_4069 gate_inverter;

    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(1), nts::Tristate::UNDEFINED);
}

// MODULE 2
Test(inverter, false_result_2)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(2, nts::Tristate::TRUE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(3), nts::Tristate::FALSE);
}

Test(inverter, true_test_2)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(2, nts::Tristate::FALSE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(3), nts::Tristate::TRUE);
}

Test(inverter, undefined_test_2)
{
    Inverter_4069 gate_inverter;

    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(3), nts::Tristate::UNDEFINED);
}

// MODULE 3
Test(inverter, false_result_3)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(4, nts::Tristate::TRUE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(5), nts::Tristate::FALSE);
}

Test(inverter, true_test_3)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(4, nts::Tristate::FALSE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(5), nts::Tristate::TRUE);
}

Test(inverter, undefined_test_3)
{
    Inverter_4069 gate_inverter;

    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(5), nts::Tristate::UNDEFINED);
}

// MODULE 4
Test(inverter, false_result_4)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(8, nts::Tristate::TRUE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(7), nts::Tristate::FALSE);
}

Test(inverter, true_test_4)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(8, nts::Tristate::FALSE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(7), nts::Tristate::TRUE);
}

Test(inverter, undefined_test_4)
{
    Inverter_4069 gate_inverter;

    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(7), nts::Tristate::UNDEFINED);
}

// MODULE 5
Test(inverter, false_result_5)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(10, nts::Tristate::TRUE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(9), nts::Tristate::FALSE);
}

Test(inverter, true_test_5)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(10, nts::Tristate::FALSE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(9), nts::Tristate::TRUE);
}

Test(inverter, undefined_test_5)
{
    Inverter_4069 gate_inverter;

    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(9), nts::Tristate::UNDEFINED);
}

// MODULE 6
Test(inverter, false_result_6)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(12, nts::Tristate::TRUE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(11), nts::Tristate::FALSE);
}

Test(inverter, true_test_6)
{
    Inverter_4069 gate_inverter;

    gate_inverter.setSinglePin(12, nts::Tristate::FALSE);
    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(11), nts::Tristate::TRUE);
}

Test(inverter, undefined_test_6)
{
    Inverter_4069 gate_inverter;

    gate_inverter.simulate(0);

    cr_assert_eq(gate_inverter.compute(11), nts::Tristate::UNDEFINED);
}
