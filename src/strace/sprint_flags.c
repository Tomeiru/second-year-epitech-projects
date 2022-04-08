/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines sprint_flags
*/

#include "sprint_flags.h"
#include "appendf_string.h"
#include <string.h>

static const char *ssf_part2(
    ssf_opts_t *o, char *output_ptr, char (*output_string)[4096])
{
    bool didnt_find_nothing = false;

    for (size_t i = 0; i < o->enu->size && o->flags != 0; ++i)
        if (o->enu->data[i].value != 0 && o->enu->data[i].string &&
            (o->flags & o->enu->data[i].value) == o->enu->data[i].value) {
            if (o->separator != '\0')
                *output_ptr++ = o->separator;
            output_ptr = stpcpy(output_ptr, o->enu->data[i].string);
            didnt_find_nothing = true;
            o->separator = '|';
            o->flags &= ~o->enu->data[i].value;
        }
    if (o->flags != 0) {
        if (o->separator != '\0')
            *output_ptr++ = o->separator;
        if (didnt_find_nothing || o->separator != '\0')
            output_ptr = STRACE_APPENDF_STRING(
                o->self, (*output_string), output_ptr, "%#jx", o->flags);
    } else if (!didnt_find_nothing)
        return (NULL);
    return (output_ptr != (*output_string) ? (*output_string) : NULL);
}

const char *strace_sprint_flags(ssf_opts_t *o)
{
    static char output_string[4096];
    char *output_ptr = stpcpy(output_string, o->prefix);

    if (o->flags == 0 && o->enu->data->value == 0 &&
        o->enu->data->string != NULL) {
        if (o->separator != '\0')
            *output_ptr++ = o->separator;
        strcpy(output_ptr, o->enu->data->string);
        return (output_string);
    }
    return (ssf_part2(o, output_ptr, &output_string));
}
