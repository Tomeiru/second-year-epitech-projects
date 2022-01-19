/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** tests_CHAR
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "char.h"
Object *new(const Class *class, ...);
void delete(Object *ptr);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(new, char_basic, .init=redirect_all_stdout)
{
    Object  *integer = new(Char, 'A');

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Char (A)>\n", "");
}

Test(new, char_zero, .init=redirect_all_stdout)
{
    Object  *integer = new(Char, '0');

    printf("int = %s\n", str(integer));

    delete(integer);
    fflush(stdout);
    cr_assert_stdout_eq_str("int = <Char (0)>\n", "");
}

Test(addition, char_add, .init=redirect_all_stdout)
{
    Object  *c1 = new(Char, 'A');
    Object  *c2 = new(Char, 1);

    printf("%s + %s = %s\n", str(c1), str(c2), str(addition(c1, c2)));
    delete(c1);
    delete(c2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Char (A)> + <Char (\001)> = <Char (B)>\n", "");
}

Test(subtraction, char_sub, .init=redirect_all_stdout)
{
    Object  *c1 = new(Char, 'B');
    Object  *c2 = new(Char, 1);

    printf("%s - %s = %s\n", str(c1), str(c2), str(subtraction(c1, c2)));
    delete(c1);
    delete(c2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Char (B)> - <Char (\001)> = <Char (A)>\n", "");
}

Test(multiplication, char_mul, .init=redirect_all_stdout)
{
    Object  *c1 = new(Char, '!');
    Object  *c2 = new(Char, 1);

    printf("%s * %s = %s\n", str(c1), str(c2), str(multiplication(c1, c2)));
    delete(c1);
    delete(c2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Char (!)> * <Char (\001)> = <Char (!)>\n", "");
}

Test(division, char_div, .init=redirect_all_stdout)
{
    Object  *c1 = new(Char, 'A');
    Object  *c2 = new(Char, 1);

    printf("%s / %s = %s\n", str(c1), str(c2), str(division(c1, c2)));
    delete(c1);
    delete(c2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Char (A)> / <Char (\001)> = <Char (A)>\n", "");
}

Test(eq, char_eq_true)
{
    Object  *c1 = new(Char, 'A');
    Object  *c2 = new(Char, 'A');

    delete(c1);
    delete(c2);
    cr_assert_eq(1, eq(c1, c2));
}

Test(eq, char_eq_false)
{
    Object  *c1 = new(Char, 'A');
    Object  *c2 = new(Char, 'B');

    delete(c1);
    delete(c2);
    cr_assert_eq(0, eq(c1, c2));
}

Test(gt, char_gt_true)
{
    Object  *c1 = new(Char, 'B');
    Object  *c2 = new(Char, 'A');

    delete(c1);
    delete(c2);
    cr_assert_eq(1, gt(c1, c2));
}

Test(gt, char_gt_false)
{
    Object  *c1 = new(Char, 'A');
    Object  *c2 = new(Char, 'B');

    delete(c1);
    delete(c2);
    cr_assert_eq(0, gt(c1, c2));
}

Test(lt, char_lt_true)
{
    Object  *c1 = new(Char, 'A');
    Object  *c2 = new(Char, 'B');

    delete(c1);
    delete(c2);
    cr_assert_eq(1, lt(c1, c2));
}

Test(lt, char_lt_false)
{
    Object  *c1 = new(Char, 'B');
    Object  *c2 = new(Char, 'A');

    delete(c1);
    delete(c2);
    cr_assert_eq(0, lt(c1, c2));
}