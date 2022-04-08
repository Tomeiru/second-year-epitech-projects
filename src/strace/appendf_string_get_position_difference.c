/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines appendf_string_get_position_difference
*/

#include "appendf_string.h"
#include "print_error_message/and_die.h"

size_t strace_appendf_string_get_position_difference(
    struct strace *self, char *string, size_t size, char *position)
{
    if ((string + size) < string)
        strace_print_error_message_and_die(self,
            "strace_appendf_string_get_position_difference: string size "
            "overflow (%p+%zu)", string, size);
    if ((string + size) < position)
        strace_print_error_message_and_die(self,
            "strace_appendf_string_get_position_difference: got position (%p) "
            "beyond string (%p+%zu)", position, string, size);
    if (string > position)
        strace_print_error_message_and_die(self,
            "strace_appendf_string_get_position_difference: got position %p "
            "before string %p", position, string);
    return (position - string);
}
