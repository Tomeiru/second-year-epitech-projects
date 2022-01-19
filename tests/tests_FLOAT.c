/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** tests_FLOAT
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "float.h"
Object *new(const Class *class, ...);
void delete(Object *ptr);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(new, float_positive, .init=redirect_all_stdout)
{
    Object  *integer = new(Float, 42.42F);

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Float (42.419998)>\n", "");
}

Test(new, float_negative, .init=redirect_all_stdout)
{
    Object  *integer = new(Float, -42.42F);

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Float (-42.419998)>\n", "");
}

Test(new, float_null, .init=redirect_all_stdout)
{
    Object  *integer = new(Float, 0.0F);

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Float (0.000000)>\n", "");
}

Test(addition, float_add, .init=redirect_all_stdout)
{
    Object  *i1 = new(Float, 41.99F);
    Object  *i2 = new(Float, 0.01F);

    printf("%s + %s = %s\n", str(i1), str(i2), str(addition(i1, i2)));
    delete(i1);
    delete(i2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Float (41.990002)> + <Float (0.010000)> = <Float (42.000000)>\n", "");
}

Test(subtraction, float_sub, .init=redirect_all_stdout)
{
    Object  *i1 = new(Float, 42.01F);
    Object  *i2 = new(Float, 0.01F);

    printf("%s - %s = %s\n", str(i1), str(i2), str(subtraction(i1, i2)));
    delete(i1);
    delete(i2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Float (42.009998)> - <Float (0.010000)> = <Float (42.000000)>\n", "");
}

Test(division, float_div, .init=redirect_all_stdout)
{
    Object  *i1 = new(Float, 84.84F);
    Object  *i2 = new(Float, 2.0F);

    printf("%s / %s = %s\n", str(i1), str(i2), str(division(i1, i2)));
    delete(i1);
    delete(i2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Float (84.839996)> / <Float (2.000000)> = <Float (42.419998)>\n", "");
}

Test(eq, float_eq_true)
{
    Object  *i1 = new(Float, 42.42F);
    Object  *i2 = new(Float, 42.42F);

    delete(i1);
    delete(i2);
    cr_assert_eq(1, eq(i1, i2));
}

Test(eq, float_eq_false)
{
    Object  *i1 = new(Float, 42.42F);
    Object  *i2 = new(Float, 42.41F);

    delete(i1);
    delete(i2);
    cr_assert_eq(0, eq(i1, i2));
}

Test(gt, float_gt_true)
{
    Object  *i1 = new(Float, 42.42F);
    Object  *i2 = new(Float, 42.41F);

    delete(i1);
    delete(i2);
    cr_assert_eq(1, gt(i1, i2));
}

Test(gt, float_gt_false)
{
    Object  *i1 = new(Float, 42.41F);
    Object  *i2 = new(Float, 42.42F);

    delete(i1);
    delete(i2);
    cr_assert_eq(0, gt(i1, i2));
}

Test(lt, float_lt_true)
{
    Object  *i1 = new(Float, 42.41F);
    Object  *i2 = new(Float, 42.42F);

    delete(i1);
    delete(i2);
    cr_assert_eq(1, lt(i1, i2));
}

Test(lt, float_lt_false)
{
    Object  *i1 = new(Float, 42.42F);
    Object  *i2 = new(Float, 42.41F);

    delete(i1);
    delete(i2);
    cr_assert_eq(0, lt(i1, i2));
}