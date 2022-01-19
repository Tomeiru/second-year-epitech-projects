/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** tests_VERTEX
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "vertex.h"
Object *new(const Class *class, ...);
void delete(Object *ptr);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(new, vertex_positive, .init=redirect_all_stdout)
{
    Object  *vertex = new(Vertex, 0, 1, 2);

    printf("vertex = %s\n", str(vertex));

    delete(vertex);
    fflush(stdout);
    cr_assert_stdout_eq_str("vertex = <Vertex (0, 1, 2)>\n", "");
}

Test(new, vertex_negative, .init=redirect_all_stdout)
{
    Object  *vertex = new(Vertex, -2, -1, 0);

    printf("vertex = %s\n", str(vertex));

    delete(vertex);
    fflush(stdout);
    cr_assert_stdout_eq_str("vertex = <Vertex (-2, -1, 0)>\n", "");
}

Test(new, vertex_life, .init=redirect_all_stdout)
{
    Object  *vertex = new(Vertex, 42, 84, 168);

    printf("vertex = %s\n", str(vertex));

    delete(vertex);
    fflush(stdout);
    cr_assert_stdout_eq_str("vertex = <Vertex (42, 84, 168)>\n", "");
}

Test(addition, vertex_add, .init=redirect_all_stdout)
{
    Object  *v1 = new(Vertex, 1, 2, 3);
    Object  *v2 = new(Vertex, 4, 5, 6);

    printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    delete(v1);
    delete(v2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Vertex (1, 2, 3)> + <Vertex (4, 5, 6)> = <Vertex (5, 7, 9)>\n", "");
}

Test(subtraction, vertex_sub, .init=redirect_all_stdout)
{
    Object  *v1 = new(Vertex, 1, 2, 3);
    Object  *v2 = new(Vertex, 4, 5, 6);

    printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    delete(v1);
    delete(v2);
    fflush(stdout);
    cr_assert_stdout_eq_str("<Vertex (1, 2, 3)> - <Vertex (4, 5, 6)> = <Vertex (-3, -3, -3)>\n", "");
}