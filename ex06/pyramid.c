/*
** EPITECH PROJECT, 2022
** AM
** File description:
** pyramid
*/

#include <stdlib.h>

size_t get_path_numb(unsigned int size)
{
    size_t ret = 1;

    for (int i = 1; i < size; i++)
        ret *= 2;
    return (ret);
}

char *set_up_binary_str(unsigned int size)
{
    char *binary_str = malloc(sizeof(size + 1));

    for (int i = 0; i < size; i++)
        binary_str[i] = '0';
    binary_str[size - 1] = '\0';
    return (binary_str);
}

char *increment_binary_str(char *binary_str, unsigned int size)
{
    for (unsigned int i = size - 1; i > 0; i--) {
        if (binary_str[i] == '0') {
            binary_str[i] = '1';
            return (binary_str);
        }binary_str[i] = '0';
    }
    return (binary_str);
}

int pyramid_path(unsigned int size, const unsigned int **map)
{
    size_t path_numb = get_path_numb(size);
    int ret = 2147483647;
    int contender = 0;
    int min = 0;
    char *binary_str = set_up_binary_str(size);

    for (size_t i = 0; i < path_numb; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if (binary_str[j] == '0') {
                contender += map[j][min];
                continue;
            }contender += map[j][min + 1];
            min += 1;
        }if (contender < ret)
            ret = contender;
        contender = 0;
        min = 0;
        binary_str = increment_binary_str(binary_str, size);
    }free(binary_str);
    return (ret);
}