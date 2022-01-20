/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_join
*/

#include "string.h"

static int get_len_c(const char  *const *array)
{
    int ret = 0;

    for (int i = 0; array[i] != NULL; i++)
        ret += (strlen(array[i]) + 1);
    return (ret);
}

static int get_len_s(const string_t  *const *array)
{
    int ret = 0;

    for (int i = 0; array[i] != NULL; i++)
        ret += (strlen(array[i]->str) + 1);
    return (ret);
}

void join_c(string_t *this, char delim, const char *const *array)
{
    int len = 0;
    char delim_str[2] = {
        delim, '\0'
    };

    if (this == NULL || array == NULL)
        return;
    len = get_len_c(array);
    printf("%i\n", len);
    free(this->str);
    this->str = malloc(sizeof(char) * len);
    this->str[0] = '\0';
    for (int i = 0; array[i] != NULL; i++) {
        strcat(this->str, array[i]);
        if (array[i + 1] == NULL)
            break;
        strcat(this->str, delim_str);
    }
}

void join_s(string_t *this, char delim, const string_t *const *array)
{
    int len = 0;
    char delim_str[2] = {
        delim, '\0'
    };

    if (this == NULL || array == NULL)
        return;
    len = get_len_s(array);
    free(this->str);
    this->str = malloc(sizeof(char) * len);
    this->str[0] = '\0';
    for (int i = 0; array[i] != NULL; i++) {
        strcat(this->str, array[i]->str);
        if (array[i + 1] == NULL)
            break;
        strcat(this->str, delim_str);
    }
}
