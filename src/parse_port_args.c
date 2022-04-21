/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** parse_port_args
*/

#include "myftp.h"

int *get_len_array(char *args)
{
    int *len_arr = malloc(sizeof(int) * 6);
    int iii = 0;

    for (int i = 0; i < 6;) {
        if (isdigit(args[iii])) {
            iii++;
            len_arr[i]++;
            continue;
        }
        len_arr[i]++;
        i++;
        iii++;
    }
    return (len_arr);
}

char **port_to_array(char *args)
{
    char **arr = malloc(sizeof(char *) * 7);
    int *len_array = get_len_array(args);
    int ii = 0;
    int iii = 0;

    for (int i = 0; i < 6;) {
        if (ii == 0)
            arr[i] = malloc(sizeof(char) * len_array[i]);
        if (isdigit(args[iii])) {
            arr[i][ii++] = args[iii++];
            continue;
        }arr[i][ii++] = '\0';
        i++;
        ii = 0;
        iii++;
    }arr[6] = NULL;
    free(len_array);
    return (arr);
}

int free_number_array(char **number_arr)
{
    for (int i = 0; i < 6; i++)
        free(number_arr[i]);
    free(number_arr);
    return (1);
}

void fill_ip_port(char **number_arr, char **ip, char **port)
{
    *ip = malloc(sizeof(char) * (strlen(number_arr[0]) + strlen(number_arr[1]) +
    strlen(number_arr[2]) + strlen(number_arr[3]) + 4));
    *ip[0] = '\0';
    for (int i = 0 ; i < 4; i++) {
        *ip = strcat(*ip, number_arr[i]);
        if (i != 3)
            *ip = strcat(*ip, ".");
    }
    *port = malloc(sizeof(char) * (strlen(number_arr[4]) +
    strlen(number_arr[5]) + 1));
    *port[0] = '\0';
    *port = strcat(*port, number_arr[4]);
    *port = strcat(*port, number_arr[5]);
}

int parse_port_args(char *args, char **ip, char **port)
{
    char **number_arr;

    if (check_elements_port_args(args))
        return (1);
    args++;
    args[strlen(args - 1)] = '\0';
    number_arr = port_to_array(args);
    for (int i = 0; i < 4; i++)
        if (atoi(number_arr[i]) > 255)
            return (free_number_array(number_arr));
    if (atoi(number_arr[4]) > 65)
        return (free_number_array(number_arr));
    if (atoi(number_arr[4]) == 65 && atoi(number_arr[5]) > 535)
        return (free_number_array(number_arr));
    if (atoi(number_arr[5]) > 999)
        return (free_number_array(number_arr));
    fill_ip_port(number_arr, ip, port);
    free_number_array(number_arr);
    return (0);
}