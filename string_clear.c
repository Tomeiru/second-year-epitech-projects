/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_clear
*/

#include "string.h"

void clear(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
    this->str = strdup("");
}
