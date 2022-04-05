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

    printf("Average return time: %im %02is\n", minutes, seconds);
}

void standard_deviation(double a, double y)
{
    double result = ((-0.75) * (a + 2) * y) + ((0.4375) * (3.f * a + 2.f) + (y * y));
    printf("Standard deviation: %.3f\n", sqrt(result));
}

double big_f_calculator(double a, double x)
{
    double ret = 1.f - (a * exp(-x) + (4 - 3 * a) / 2 * exp(-2 * x) + (2 * a - 4) / 4 * exp(-4 * x));
    return (ret);
}

double algo(double a, double below, double above, double objective)
{
    double middle = below + ((above - below) / 2);
    double result = big_f_calculator(a, middle);

    if (above - below < 0.001)
        return (middle);
    return (result > objective ? algo(a, below, middle, objective) : algo(a, middle, above, objective));
}

double get_result(double a, double value)
{
    double lol = big_f_calculator(a, (double)1);
    int above = 1;

    for ( ; lol < value; above = above * 2)
        lol = big_f_calculator(a, (double)above);
    above /= 2;
    return (algo(a, 0, above, value));
}

void calculate_time_back(double a, int percentage)
{
    double result = get_result(a, (double)percentage / 100);
    int minutes = result;
    int seconds = round((result - minutes) * 60);

    printf("Time after which %i%% of the ducks are back: %im %02is\n", percentage, minutes, seconds);
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
    calculate_time_back(a, 50);
    calculate_time_back(a, 99);
    printf("Percentage of ducks back after 1 minute: %.1f%%\n", big_f_calculator(a, 1) * 100);
    printf("Percentage of ducks back after 2 minutes: %.1f%%\n", big_f_calculator(a, 2) * 100);
}