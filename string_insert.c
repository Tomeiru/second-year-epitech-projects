/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_insert
*/

#include "string.h"

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    char *temp;

    if (this == NULL || str == NULL)
        return;
    if (pos >= strlen(this->str))
        return (this->append_s(this, str));
    temp = malloc(sizeof(char) * (strlen(this->str) + strlen(str->str) + 1));
    temp[0] = '\0';
    temp = strncpy(temp, this->str, pos + 1);
    temp = strcat(temp, str->str);
    temp = strcat(temp, this->str + pos + 1);
    free(this->str);
    this->str = temp;
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *temp;

    if (this == NULL || str == NULL)
        return;
    if (pos >= strlen(this->str))
        return (this->append_c(this, str));
    temp = malloc(sizeof(char) * (strlen(this->str) + strlen(str) + 1));
    temp = strncpy(temp, this->str, pos);
    temp[pos] = '\0';
    temp = strcat(temp, str);
    temp = strcat(temp, this->str + pos);
    free(this->str);
    this->str = temp;
}