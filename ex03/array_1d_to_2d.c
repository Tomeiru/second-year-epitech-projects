/*
** EPITECH PROJECT, 2022
** AM
** File description:
** array_1d_to_2d
*/

#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int **temp = malloc(sizeof(int *) * (height + 1));
    int a = 0;

    for (int i = 0; i < height; i++) {
        temp[i] = malloc(sizeof(int) * (width));
        for (int j = 0; j < width; j++)
            temp[i][j] = array[a++];
    }temp[height] = NULL;
    *res = temp;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}