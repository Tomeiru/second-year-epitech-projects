/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines appendf_string_get_position_difference
*/

#include "appendf_string.h"
#include "print_error_message/and_die.h"

size_t ftrace_appendf_string_get_position_difference(
    struct ftrace *self, char *string, size_t size, char *position)
{
    if ((string + size) < string)
        ftrace_print_error_message_and_die(self,
            "ftrace_appendf_string_get_position_difference: string size "
            "overflow (%p+%zu)", string, size);
    if ((string + size) < position)
        ftrace_print_error_message_and_die(self,
            "ftrace_appendf_string_get_position_difference: got position (%p) "
            "beyond string (%p+%zu)", position, string, size);
    if (string > position)
        ftrace_print_error_message_and_die(self,
            "ftrace_appendf_string_get_position_difference: got position %p "
            "before string %p", position, string);
    return (position - string);
}
