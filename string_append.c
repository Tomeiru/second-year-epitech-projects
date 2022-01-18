/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** append_function
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *temp;

    if (this == NULL || ap == NULL)
        return;
    temp = malloc(sizeof(char) * (strlen(this->str) + strlen(ap->str) + 1));
    temp[0] = '\0';
    temp = strcat(temp, this->str);
    free(this->str);
    temp = strcat(temp, ap->str);
    this->str = temp;
}

void append_c(string_t *this, const char *ap)
{
    char *temp;

    if (this == NULL || ap == NULL)
        return;
    temp = malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
    temp[0] = '\0';
    temp = strcat(temp, this->str);
    free(this->str);
    temp = strcat(temp, ap);
    this->str = temp;
}
