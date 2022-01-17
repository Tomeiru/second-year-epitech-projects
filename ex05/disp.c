/*
** EPITECH PROJECT, 2022
** AM
** File description:
** disp
*/

#include <stdlib.h>

void disp_int_array(const int *array, size_t nmemb)
{
    for (int i = 0; i < nmemb; i++)
        printf("%i\n", array[i]);
}

void disp_array(const void *array, size_t nmemb, size_t size,
void(*print)(const void *))
{
    for (int i = 0; i < nmemb; i++) {
        print(array);
        array += size;
    }
}