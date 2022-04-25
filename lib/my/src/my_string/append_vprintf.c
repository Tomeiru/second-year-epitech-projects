/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Defines append_vprintf
*/

#include "my/my_string.h"
#include "my/internal/my_string.h"
#include "my/stdio.h"
#include <stdlib.h>

struct my_string *my_string_append_vprintf(struct my_string *self,
    const char *format, va_list arguments)
{
    int asprintf_length;
    char *asprintf_result;

    if (self == NULL || format == NULL)
        return NULL;
    asprintf_length = my_xvasprintf(&asprintf_result, format, arguments);
    my_string_append(self, asprintf_result, (unsigned)asprintf_length);
    free(asprintf_result);
    return self;
}
