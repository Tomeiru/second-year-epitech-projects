/*
** EPITECH PROJECT, 2022
** AM
** File description:
** tests_PRINT
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "print.h"
void do_action(action_t action, const char *str);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(do_action, print_normal, .init=redirect_all_stdout)
{
    action_t action;
    const char *str = "Bonjour";

    do_action(PRINT_NORMAL, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("Bonjour\n", "");
}

Test(do_action, print_reverse, .init=redirect_all_stdout)
{
    action_t action;
    const char *str = "Bonsoir";

    do_action(PRINT_REVERSE, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("riosnoB\n", "");
}

Test(do_action, print_upper, .init=redirect_all_stdout)
{
    action_t action;
    const char *str = "minuSCULE0az";

    do_action(PRINT_UPPER, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("MINUSCULE0AZ\n", "");
}

Test(do_action, print_42, .init=redirect_all_stdout)
{
    action_t action;
    const char *str = "KEKW";

    do_action(PRINT_42, str);
    fflush(stdout);
    cr_assert_stdout_eq_str("42\n", "");
}