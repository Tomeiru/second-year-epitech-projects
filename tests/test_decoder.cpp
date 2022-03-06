/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** test_decoder
*/

#include "Decoder_4514.hpp"
#include <criterion/criterion.h>

Test(decoder, strobe)
{
    Decoder_4514 decoder;

    decoder.setSinglePin(0, nts::Tristate::FALSE);
    decoder.simulate(1);
    cr_expect_eq(decoder.compute(10), nts::Tristate::UNDEFINED);
}

Test(decoder, inihibit)
{
    Decoder_4514 decoder;

    decoder.setSinglePin(0, nts::Tristate::TRUE);
    decoder.setSinglePin(22, nts::Tristate::TRUE);
    decoder.simulate(1);
    cr_expect_eq(decoder.compute(10), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(7), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(17), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(16), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(19), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(18), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(13), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(12), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(15), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(14), nts::Tristate::FALSE);
}

Test(decoder, testing_one_output)
{
    Decoder_4514 decoder;

    decoder.setSinglePin(0, nts::Tristate::TRUE);
    decoder.setSinglePin(22, nts::Tristate::FALSE);
    decoder.setSinglePin(1, nts::Tristate::TRUE);
    decoder.setSinglePin(2, nts::Tristate::FALSE);
    decoder.setSinglePin(20, nts::Tristate::TRUE);
    decoder.setSinglePin(21, nts::Tristate::FALSE);
    decoder.simulate(1);
    cr_expect_eq(decoder.compute(10), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(7), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(5), nts::Tristate::TRUE);
    cr_expect_eq(decoder.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(17), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(16), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(19), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(18), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(13), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(12), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(15), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(14), nts::Tristate::FALSE);
}

Test(decoder, testing_another_output)
{
    Decoder_4514 decoder;

    decoder.setSinglePin(0, nts::Tristate::TRUE);
    decoder.setSinglePin(22, nts::Tristate::FALSE);
    decoder.setSinglePin(1, nts::Tristate::TRUE);
    decoder.setSinglePin(2, nts::Tristate::TRUE);
    decoder.setSinglePin(20, nts::Tristate::TRUE);
    decoder.setSinglePin(21, nts::Tristate::TRUE);
    decoder.simulate(1);
    cr_expect_eq(decoder.compute(10), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(8), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(9), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(7), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(6), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(5), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(4), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(3), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(17), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(16), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(19), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(18), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(13), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(12), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(15), nts::Tristate::FALSE);
    cr_expect_eq(decoder.compute(14), nts::Tristate::TRUE);
}