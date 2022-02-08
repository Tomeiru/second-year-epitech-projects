/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** easy_functions
*/

#include <unistd.h>
#include <string.h>

void myputchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        myputchar(str[i]);
}

size_t my_strlen(char *str)
{
    return (strlen(str));
}

void malloc(size_t size)
{
    (void)(size);
    write(2, "Flying cats are the best!!!\n", 28);
}