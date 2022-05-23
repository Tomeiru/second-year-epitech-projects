/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** destroy
*/

#include "teams.h"

// TODO : delete teams
void save_destroy(save_t *save)
{
    delete_list(save->users);
    delete_list(save->discussions);
    free(save);
}
