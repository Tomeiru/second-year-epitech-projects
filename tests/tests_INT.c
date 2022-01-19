/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** tests_INT
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "int.h"
Object *new(const Class *class, ...);
void delete(Object *ptr);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(new, int_positive, .init=redirect_all_stdout)
{
    Object  *integer = new(Int, 42);

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Int (42)>\n", "");
}

Test(new, int_negative, .init=redirect_all_stdout)
{
    Object  *integer = new(Int, -42);

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Int (-42)>\n", "");
}

Test(new, int_null, .init=redirect_all_stdout)
{
    Object  *integer = new(Int, 0);

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Int (0)>\n", "");
}

Test(addition, int_add, .init=redirect_all_stdout)
{
    Object  *i1 = new(Int, 42);
    Object  *i2 = new(Int, 42);

    printf("%s + %s = %s\n", str(i1), str(i2), str(addition(i1, i2)));
    delete(i1);
    delete(i2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Int (42)> + <Int (42)> = <Int (84)>\n", "");
}

Test(subtraction, int_sub, .init=redirect_all_stdout)
{
    Object  *i1 = new(Int, 42);
    Object  *i2 = new(Int, 42);

    printf("%s - %s = %s\n", str(i1), str(i2), str(subtraction(i1, i2)));
    delete(i1);
    delete(i2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Int (42)> - <Int (42)> = <Int (0)>\n", "");
}

Test(multiplication, int_mul, .init=redirect_all_stdout)
{
    Object  *i1 = new(Int, 21);
    Object  *i2 = new(Int, 2);

    printf("%s * %s = %s\n", str(i1), str(i2), str(multiplication(i1, i2)));
    delete(i1);
    delete(i2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Int (21)> * <Int (2)> = <Int (42)>\n", "");
}

Test(division, int_div, .init=redirect_all_stdout)
{
    Object  *i1 = new(Int, 84);
    Object  *i2 = new(Int, 2);

    printf("%s / %s = %s\n", str(i1), str(i2), str(division(i1, i2)));
    delete(i1);
    delete(i2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Int (84)> / <Int (2)> = <Int (42)>\n", "");
}

Test(eq, int_eq_true)
{
    Object  *i1 = new(Int, 42);
    Object  *i2 = new(Int, 42);

    delete(i1);
    delete(i2);
    cr_assert_eq(1, eq(i1, i2));
}

Test(eq, int_eq_false)
{
    Object  *i1 = new(Int, 42);
    Object  *i2 = new(Int, 41);

    delete(i1);
    delete(i2);
    cr_assert_eq(0, eq(i1, i2));
}

Test(gt, int_gt_true)
{
    Object  *i1 = new(Int, 42);
    Object  *i2 = new(Int, 41);

    delete(i1);
    delete(i2);
    cr_assert_eq(1, gt(i1, i2));
}

Test(gt, int_gt_false)
{
    Object  *i1 = new(Int, 41);
    Object  *i2 = new(Int, 42);

    delete(i1);
    delete(i2);
    cr_assert_eq(0, gt(i1, i2));
}

Test(lt, int_lt_true)
{
    Object  *i1 = new(Int, 41);
    Object  *i2 = new(Int, 42);

    delete(i1);
    delete(i2);
    cr_assert_eq(1, lt(i1, i2));
}

Test(lt, int_lt_false)
{
    Object  *i1 = new(Int, 42);
    Object  *i2 = new(Int, 41);

    delete(i1);
    delete(i2);
    cr_assert_eq(0, lt(i1, i2));
}