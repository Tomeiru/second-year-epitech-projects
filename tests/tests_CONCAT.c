/*
** EPITECH PROJECT, 2022
** test
** File description:
** test concat_string
*/

#include <criterion/criterion.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res);
void concat_struct(concat_t *str);

Test (concat_strings, basic)
{
    char *str1 = "Je suis la première partie,";
    char *str2 = " suivie de la deuxième";
    char *res = NULL;

    concat_strings(str1, str2, &res);
    cr_assert_str_eq(res, "Je suis la première partie, suivie de la deuxième");
}

Test (conca_struct, basic)
{
    concat_t *str = malloc(sizeof(concat_t));

    str->str1 = "Je suis de retour!";
    str->str2 = " Pour vous jouer de mauvais tours!";
    str->res = NULL;

    concat_struct(str);
    cr_assert_str_eq(str->res,
    "Je suis de retour! Pour vous jouer de mauvais tours!");
    free(str);
}