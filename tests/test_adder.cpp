/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_adder
*/

#include "Adder_4008.hpp"
#include <criterion/criterion.h>

Test(adder, testing_classic_add)
{
    Adder_4008 adder;

    // SET ALL INPUT TO FALSE (An Bn and C)
    adder.setSinglePin(6, nts::Tristate::FALSE);
    adder.setSinglePin(5, nts::Tristate::FALSE);
    adder.setSinglePin(4, nts::Tristate::FALSE);
    adder.setSinglePin(3, nts::Tristate::FALSE);
    adder.setSinglePin(2, nts::Tristate::FALSE);
    adder.setSinglePin(1, nts::Tristate::FALSE);
    adder.setSinglePin(0, nts::Tristate::FALSE);
    adder.setSinglePin(14, nts::Tristate::FALSE);
    adder.setSinglePin(8, nts::Tristate::FALSE);
    adder.simulate(0);
    cr_expect_eq(adder.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(adder.compute(10), nts::Tristate::FALSE);
    adder.setSinglePin(5, nts::Tristate::TRUE);
    adder.simulate(0);
    cr_expect_eq(adder.compute(9), nts::Tristate::TRUE);
    cr_expect_eq(adder.compute(10), nts::Tristate::FALSE);
    adder.setSinglePin(6, nts::Tristate::TRUE);
    adder.simulate(0);
    cr_expect_eq(adder.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(adder.compute(10), nts::Tristate::TRUE);
    adder.setSinglePin(6, nts::Tristate::FALSE);
    adder.setSinglePin(8, nts::Tristate::TRUE);
    adder.simulate(0);
    cr_expect_eq(adder.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(adder.compute(10), nts::Tristate::TRUE);
    adder.setSinglePin(6, nts::Tristate::TRUE);
    adder.setSinglePin(5, nts::Tristate::TRUE);
    adder.setSinglePin(8, nts::Tristate::TRUE);
    adder.simulate(0);
    cr_expect_eq(adder.compute(9), nts::Tristate::TRUE);
    cr_expect_eq(adder.compute(10), nts::Tristate::TRUE);
}

Test(adder, testing_all_output)
{
    Adder_4008 adder;

    // SET ALL INPUT TO FALSE (An Bn and C)
    adder.setSinglePin(6, nts::Tristate::TRUE);
    adder.setSinglePin(5, nts::Tristate::TRUE);
    adder.setSinglePin(4, nts::Tristate::TRUE);
    adder.setSinglePin(3, nts::Tristate::TRUE);
    adder.setSinglePin(2, nts::Tristate::TRUE);
    adder.setSinglePin(1, nts::Tristate::TRUE);
    adder.setSinglePin(0, nts::Tristate::TRUE);
    adder.setSinglePin(14, nts::Tristate::TRUE);
    adder.setSinglePin(8, nts::Tristate::TRUE);
    adder.simulate(0);
    cr_expect_eq(adder.compute(9), nts::Tristate::TRUE);
    cr_expect_eq(adder.compute(10), nts::Tristate::TRUE);
    cr_expect_eq(adder.compute(11), nts::Tristate::TRUE);
    cr_expect_eq(adder.compute(12), nts::Tristate::TRUE);
    cr_expect_eq(adder.compute(13), nts::Tristate::TRUE);
}