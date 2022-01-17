/*
** EPITECH PROJECT, 2022
** AM
** File description:
** print
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char temp;
    int str_len = strlen(str);
    char *revstr = malloc(sizeof(char) * (str_len + 1));
    int j = str_len - 1;

    for (int i = 0; i <= j; i++){
        temp = str[i];
        revstr[i] = str[j];
        revstr[j--] = temp;
    }revstr[str_len] = '\0';
    printf("%s\n", revstr);
    free(revstr);
}

void print_upper(const char *str)
{
    int str_len = strlen(str);
    char *uppstr = malloc(sizeof(char) * (str_len + 1));

    for (int i = 0; str[i]; i++){
        if (str[i] >= 97 && str[i] <= 122)
            uppstr[i] = str[i] - 32;
        else
            uppstr[i] = str[i];
    }uppstr[str_len] = '\0';
    printf("%s\n", uppstr);
    free(uppstr);
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (* print_func[4])(const char *) = {
        print_normal, print_reverse, print_upper, print_42
    };

    print_func[action](str);
}