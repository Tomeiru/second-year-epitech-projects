/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares list_append
*/

#pragma once

#include "../../strace.h"

void strace_list_append(struct strace_list_item *self,
    struct strace_list_item *appended_item);
