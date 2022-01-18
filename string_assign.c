/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** assign_function
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL)
        return;
    free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this == NULL || s == NULL)
        return;
    free(this->str);
    this->str = strdup(s);
}