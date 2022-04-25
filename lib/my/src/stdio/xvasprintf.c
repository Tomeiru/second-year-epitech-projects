/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xvasprintf
*/

#include "my/stdio.h"
#include "my/internal/stdlib.h"

int my_xvasprintf(char **MY_RESTRICT result_string_ptr,
    const char *MY_RESTRICT format, va_list arguments)
{
    int result = vasprintf(result_string_ptr, format, arguments);

    if (result < 0)
        my_xmalloc_out_of_memory(-1);
    return result;
}
