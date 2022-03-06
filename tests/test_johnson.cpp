/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_johnson
*/

#include "Johnson_4017.hpp"
#include "Clock.hpp"
#include <criterion/criterion.h>

Test(johnson, master_reset)
{
    Johnson_4017 john;

    john.setSinglePin(15, nts::Tristate::TRUE);
    john.simulate(0);
    cr_expect_eq(john.compute(2), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
}

Test(Johnson, whole_loop)
{
    Johnson_4017 john;
    std::size_t tick = 0;
    john.setSinglePin(15, nts::Tristate::FALSE);
    john.setSinglePin(13, nts::Tristate::TRUE);
    john.setSinglePin(12, nts::Tristate::FALSE);
    john.simulate(tick);
    cr_expect_eq(john.compute(2), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::FALSE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::FALSE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::FALSE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::TRUE);
    cr_assert_eq(john.compute(11), nts::Tristate::FALSE);
    john.simulate(++tick);
    cr_expect_eq(john.compute(2), nts::Tristate::TRUE);
    cr_expect_eq(john.compute(1), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(0), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(john.compute(10), nts::Tristate::FALSE);
    cr_assert_eq(john.compute(11), nts::Tristate::TRUE);
}