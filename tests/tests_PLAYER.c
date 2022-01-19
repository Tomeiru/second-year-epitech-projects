/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** tests_PLAYER
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "player.h"
Object *new(const Class *class, ...);
void delete(Object *ptr);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(new, basic, .init=redirect_all_stdout)
{
    Object  *player = new(Player);

    delete(player);
    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n~Player()\n", "");
}