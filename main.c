/*
** EPITECH PROJECT, 2022
** 204ducks
** File description:
** main
*/

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int check_a(char *a)
{
    if (!strlen(a))
        return (0);
    int dot_count = 0;

    for (int i = 0; a[i]; i++) {
        if (a[i] == '.') {
            dot_count++;
            if (dot_count == 1)
                continue;
            return (0);
        }
        if (!isdigit(a[i]))
            return (0);
    }
    return (1);
}

void return_time(double a, double *e)
{
    double result = 3.f *((a + 2.f) / 8.f);
    *e = result;
    int minutes = result;
    int seconds = round((result - minutes) * 60);

    printf("Average return time: %im %is\n", minutes, seconds);
}

void standard_deviation(double a, double y)
{
    double result = ((-0.75) * (a + 2) * y) + ((0.4375) * (3.f * a + 2.f) + (y * y));
    printf("Standard deviation: %.3f\n", sqrt(result));
}

int main(int ac, char **av)
{
    double a = 0;
    double e = 0;

    if (ac != 2)
        return (84);
    if (!check_a(av[1]))
        return (84);
    a = atof(av[1]);
    if (a <= 0 || a >= 2.5)
        return (84);
    return_time(a, &e);
    standard_deviation(a, e);
    printf("%f\n", 0.399576 - 0.122379 * a);
}