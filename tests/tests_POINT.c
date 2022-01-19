/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** tests_POINT
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "point.h"
Object *new(const Class *class, ...);
void delete(Object *ptr);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(new, point_regular, .init=redirect_all_stdout)
{
    Object  *point = new(Point, 42, -42);

    printf("point = %s\n", str(point));

    delete(point);
    fflush(stdout);
    cr_assert_stdout_eq_str("point = <Point (42, -42)>\n", "");
}

Test(new, point_reverse, .init=redirect_all_stdout)
{
    Object  *point = new(Point, -42, 42);

    printf("point = %s\n", str(point));

    delete(point);
    fflush(stdout);
    cr_assert_stdout_eq_str("point = <Point (-42, 42)>\n", "");
}

Test(new, point_null, .init=redirect_all_stdout)
{
    Object  *point = new(Point, 0, 0);

    printf("point = %s\n", str(point));

    delete(point);
    fflush(stdout);
    cr_assert_stdout_eq_str("point = <Point (0, 0)>\n", "");
}

Test(addition, point_add, .init=redirect_all_stdout)
{
    Object  *p1 = new(Point, 12, 13);
    Object  *p2 = new(Point, 2, 2);

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    delete(p1);
    delete(p2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Point (12, 13)> + <Point (2, 2)> = <Point (14, 15)>\n", "");
}

Test(subtraction, point_sub, .init=redirect_all_stdout)
{
    Object  *p1 = new(Point, 12, 13);
    Object  *p2 = new(Point, 2, 2);

    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));
    delete(p1);
    delete(p2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Point (12, 13)> - <Point (2, 2)> = <Point (10, 11)>\n", "");
}