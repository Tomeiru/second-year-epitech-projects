/*
** EPITECH PROJECT, 2022
** test
** File description:
** test concat_string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res);
void array_2d_free(int **array, size_t height, size_t width);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test (array_1d_to_2d, basic, .init=redirect_all_stdout)
{
    int array[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    };
    int **res = NULL;
    size_t height = 3;
    size_t width = 5;

    array_1d_to_2d(array, height, width, &res);
    fprintf(stdout, "%d\n", res[2][2]);
    fprintf(stdout, "%d\n", res[0][0]);
    fprintf(stdout, "%d\n", res[1][4]);
    fflush(stdout);
    cr_assert_stdout_eq_str("13\n1\n10\n", "");
    array_2d_free(res, height, width);
}