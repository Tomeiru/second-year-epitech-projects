/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines translate_symbol_name
*/

#include "translate_symbol_name.h"
#include <string.h>

const char *ftrace_translate_symbol_name(const char *name)
{
    if (strcmp(name, "__printf") == 0 ||
        strcmp(name, "_IO_printf") == 0)
        return ("printf");
    return (name);
}
