/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** main
*/

#include "panoramix.h"

static int is_array_number(char **args)
{
    int ret = 1;

    for (int i = 0; args[i]; i++) {
        for (int ii = 0; args[i][ii]; ii++)
            ret = (!isdigit(args[i][ii])) ? 0 : ret;
    }
    return (ret);
}

static int check_zero(panoramix_t *info)
{
    if (!NB_VILLA || !POT_SIZE || !NB_FIGHT || !NB_REFIL)
        return (0);
    return (1);
}

void create_villagers_array(panoramix_t **info)
{
    (*info)->villagers = malloc(sizeof(villager_t *) *
    ((*info)->nb_villagers + 1));

    for (unsigned long i = 0; i < (*info)->nb_villagers; i++) {
        (*info)->villagers[i] = malloc(sizeof(villager_t));
        (*info)->villagers[i]->id = i;
        (*info)->villagers[i]->nb_fights_left = (*info)->nb_fights;
        (*info)->villagers[i]->drink = 0;
        (*info)->villagers[i]->info = (*info);
    }
    (*info)->villagers[(*info)->nb_villagers] = NULL;
}

static int fill_struct(char **args, panoramix_t **info)
{
    if (!is_array_number(args))
        return (84);
    (*info)->nb_villagers = strtoul(args[0], NULL, 10);
    (*info)->pot_size = strtoul(args[1], NULL, 10);
    (*info)->nb_fights = strtoul(args[2], NULL, 10);
    (*info)->nb_refills = strtoul(args[3], NULL, 10);
    (*info)->pot_quantity = (*info)->pot_size;
    sem_init(&(*info)->pano_sem, 0, 0);
    sem_init(&(*info)->vil_sem, 0, 0);
    pthread_mutex_init(&(*info)->mutex, NULL);
    if (!check_zero(*info))
        return (84);
    create_villagers_array(info);
    return (0);
}

int main(int ac, char **av)
{
    panoramix_t *info = malloc(sizeof(panoramix_t));

    if (!info)
        return (print_error("malloc error"));
    if (ac != 5 || fill_struct(++av, &info) == 84) {
        free(info);
        return (print_error("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_f\
ights> <nb_refills>\nValues must be >0"));
    }
    return (panoramix(info));
}