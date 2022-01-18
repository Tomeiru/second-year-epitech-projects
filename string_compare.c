/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_compare
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL)
        return (-9999);
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || str == NULL)
        return (-9999);
    return (strcmp(this->str, str));
}