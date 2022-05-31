/*
** EPITECH PROJECT, 2022
** teams
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

int is_not_number(char *s);
int is_sep(char c, char *sep);
char *rm_sep_aft(char *str, char *sep);
char *rm_sep_bef(char *str, char *sep);
int get_len_array(void *arr, size_t size);
char **teams_cl_to_arr(char *str);

#endif /* !UTILS_H_ */
