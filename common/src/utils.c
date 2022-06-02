/*
** EPITECH PROJECT, 2022
** teams
** File description:
** utils
*/

#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <uuid/uuid.h>
#include "chained_list.h"

int is_not_number(char *s)
{
    for (int i = 0; s[i]!= '\0'; i++) {
        if (isdigit(s[i]) == 0)
            return (1);
    }
    return (0);
}

int get_len_array(void *arr, size_t size)
{
    int len = 0;

    while (((int *)(arr))[0]) {
        len++;
        arr += size;
    }
    return (len);
}

bool does_list_contains_uuid(uuid_t uuid, uuid_list_t list)
{
    for (uuid_list_t cpy = list; cpy; cpy = (uuid_list_t) cpy->next) {
        if (!uuid_compare(uuid, cpy->uuid))
            return true;
    }
    return false;
}
