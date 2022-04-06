/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares list_remove
*/

#pragma once

#include "../../strace.h"

// Removes the first element of the list with the assumption that this is just
// the dummy list head
void strace_list_remove(struct strace_list_item *list);
