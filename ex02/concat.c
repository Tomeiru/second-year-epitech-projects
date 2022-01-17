/*
** EPITECH PROJECT, 2022
** AM
** File description:
** concat
*/

#include <stdlib.h>
#include <string.h>

void concat_strings(const char *str1, const char *str2, char **res)
{
    int fst_length = strlen(str1);
    int scd_length = strlen(str2);
    int res_length = fst_length + scd_length;
    char *temp = malloc(sizeof(char) * (res_length + 1));
    int a = 0;

    for (int i = 0; i < fst_length; i++)
        temp[a++] = str1[i];
    for (int i = 0; i < scd_length - 1; i++)
        temp[a++] = str2[i];
    temp[a] = '\0';
    *res = temp;
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}