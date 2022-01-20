/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_split
*/

#include "string.h"
#include <string.h>

static int get_len(char *str, char separator)
{
    int ret = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == separator)
            ret++;
    if (ret == 0)
        return (ret);
    return (ret + 1);
}

string_t **split_s(const string_t *this, char separator)
{
    char *backup = this->str;
    char *backup_second = strdup(this->str);
    string_t **ret;
    int len = 0;
    char sp[2] = {
        separator, '\0'
    };

    if (this == NULL || this->str == NULL || !(len = get_len(this->str, sp[0])))
        return (NULL);
    ret = malloc(sizeof(string_t *) * (len + 1));
    ret[0] = malloc(sizeof(string_t));
    string_init(ret[0], strsep(&backup, sp));
    for (int i = 1; backup != NULL; i++) {
        ret[i] = malloc(sizeof(string_t));
        string_init(ret[i], strsep(&backup, sp));
    }ret[len] = NULL;
    memcpy(this->str, backup_second, sizeof(char) * (strlen(backup_second)));
    free(backup_second);
    return (ret);
}

char **split_c(const string_t *this, char separator)
{
    char *backup = this->str;
    char *backup_second = strdup(this->str);
    char **ret;
    int len = 0;
    char sp[2] = {
        separator, '\0'
    };

    if (this == NULL || this->str == NULL || !(len = get_len(this->str, sp[0])))
        return (NULL);
    ret = malloc(sizeof(char *) * (len + 1));
    ret[0] = strdup(strsep(&backup, sp));
    for (int i = 1; backup != NULL; i++)
        ret[i] = strdup(strsep(&backup, sp));
    ret[len] = NULL;
    memcpy(this->str, backup_second, sizeof(char) * (strlen(backup_second)));
    free(backup_second);
    return (ret);
}
