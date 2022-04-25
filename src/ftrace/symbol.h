/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines symbol
*/

#pragma once

#include <gelf.h>

struct ftrace_symbol {
    char *name;
    GElf_Sym symbol;
};
