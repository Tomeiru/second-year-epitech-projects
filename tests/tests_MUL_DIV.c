/*
** EPITECH PROJECT, 2022
** AM
** File description:
** tests_Z
*/

#include <criterion/criterion.h>
void mul_div_long(int a, int b, int *mul, int *div);
void mul_div_short(int *a, int *b);

Test(mul_div_long, basic_test)
{
    int a = 16;
    int b = 2;
    int mul = 0;
    int div = 0;

    mul_div_long(a, b, &mul, &div);
    cr_assert_eq(mul, 32);
    cr_assert_eq(div, 8);
}

Test(mul_div_long, test_divide_by_zero)
{
    int a = 16;
    int b = 0;
    int mul = 0;
    int div = 0;

    mul_div_long(a, b, &mul, &div);
    cr_assert_eq(mul, 0);
    cr_assert_eq(div, 42);
}

Test(mul_div_short, basic_test)
{
    int a = 32;
    int b = 4;

    mul_div_short(&a, &b);
    cr_assert_eq(a, 128);
    cr_assert_eq(b, 8);
}

Test(mul_div_short, test_divide_by_zero)
{
    int a = 32;
    int b = 0;

    mul_div_short(&a, &b);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 42);
}