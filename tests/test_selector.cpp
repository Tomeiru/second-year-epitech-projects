/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_selector
*/

#include "Selector_4512.hpp"
#include <criterion/criterion.h>

Test(selector, output_enable)
{
    Selector_4512 selector;

    selector.setSinglePin(14, nts::Tristate::TRUE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::UNDEFINED);
}

Test(selector, inhibit)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::TRUE);
    selector.setSinglePin(14, nts::Tristate::FALSE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::FALSE);
}

Test(selector, output0)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::FALSE);
    selector.setSinglePin(11, nts::Tristate::FALSE);
    selector.setSinglePin(12, nts::Tristate::FALSE);
    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::TRUE);
}

Test(selector, output1)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::TRUE);
    selector.setSinglePin(11, nts::Tristate::FALSE);
    selector.setSinglePin(12, nts::Tristate::FALSE);

    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.setSinglePin(1, nts::Tristate::FALSE);
    selector.setSinglePin(2, nts::Tristate::FALSE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::FALSE);
}

Test(selector, output2)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::FALSE);
    selector.setSinglePin(11, nts::Tristate::TRUE);
    selector.setSinglePin(12, nts::Tristate::FALSE);

    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.setSinglePin(1, nts::Tristate::FALSE);
    selector.setSinglePin(2, nts::Tristate::FALSE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::FALSE);
}

Test(selector, output3)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::TRUE);
    selector.setSinglePin(11, nts::Tristate::TRUE);
    selector.setSinglePin(12, nts::Tristate::FALSE);

    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.setSinglePin(1, nts::Tristate::FALSE);
    selector.setSinglePin(2, nts::Tristate::FALSE);
    selector.setSinglePin(3, nts::Tristate::UNDEFINED);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::UNDEFINED);
}

Test(selector, output4)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::FALSE);
    selector.setSinglePin(11, nts::Tristate::FALSE);
    selector.setSinglePin(12, nts::Tristate::TRUE);

    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.setSinglePin(1, nts::Tristate::FALSE);
    selector.setSinglePin(2, nts::Tristate::FALSE);
    selector.setSinglePin(3, nts::Tristate::UNDEFINED);
    selector.setSinglePin(4, nts::Tristate::TRUE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::TRUE);
}

Test(selector, output5)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::TRUE);
    selector.setSinglePin(11, nts::Tristate::FALSE);
    selector.setSinglePin(12, nts::Tristate::TRUE);

    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.setSinglePin(1, nts::Tristate::FALSE);
    selector.setSinglePin(2, nts::Tristate::FALSE);
    selector.setSinglePin(3, nts::Tristate::UNDEFINED);
    selector.setSinglePin(4, nts::Tristate::TRUE);
    selector.setSinglePin(5, nts::Tristate::FALSE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::FALSE);
}

Test(selector, output6)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::FALSE);
    selector.setSinglePin(11, nts::Tristate::TRUE);
    selector.setSinglePin(12, nts::Tristate::FALSE);

    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.setSinglePin(1, nts::Tristate::FALSE);
    selector.setSinglePin(2, nts::Tristate::FALSE);
    selector.setSinglePin(3, nts::Tristate::UNDEFINED);
    selector.setSinglePin(4, nts::Tristate::TRUE);
    selector.setSinglePin(5, nts::Tristate::FALSE);
    selector.setSinglePin(6, nts::Tristate::FALSE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::FALSE);
}

Test(selector, output7)
{
    Selector_4512 selector;

    selector.setSinglePin(9, nts::Tristate::FALSE);
    selector.setSinglePin(14, nts::Tristate::FALSE);

    selector.setSinglePin(10, nts::Tristate::TRUE);
    selector.setSinglePin(11, nts::Tristate::TRUE);
    selector.setSinglePin(12, nts::Tristate::TRUE);

    selector.setSinglePin(0, nts::Tristate::TRUE);
    selector.setSinglePin(1, nts::Tristate::FALSE);
    selector.setSinglePin(2, nts::Tristate::FALSE);
    selector.setSinglePin(3, nts::Tristate::UNDEFINED);
    selector.setSinglePin(4, nts::Tristate::TRUE);
    selector.setSinglePin(5, nts::Tristate::FALSE);
    selector.setSinglePin(6, nts::Tristate::FALSE);
    selector.setSinglePin(8, nts::Tristate::TRUE);
    selector.simulate(0);
    cr_assert_eq(selector.compute(13), nts::Tristate::TRUE);
}