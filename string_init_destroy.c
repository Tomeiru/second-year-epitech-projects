/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_init_destroy
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
}

void string_destroy(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
    this = NULL;
}