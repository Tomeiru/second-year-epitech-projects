/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_info
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    size_t len;

    if (this == NULL)
        return (-1);
    len = strlen(this->str);
    if (pos >= len || pos < 0)
        return (-1);
    return (this->str[pos]);
}