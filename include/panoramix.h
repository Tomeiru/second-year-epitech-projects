/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <semaphore.h>

#define UNUSED(x) (void)(x)
#define NB_VILLA info->nb_villagers
#define POT_SIZE info->pot_size
#define NB_FIGHT info->nb_fights
#define NB_REFIL info->nb_refills
#define POT_QUAN info->pot_quantity

typedef struct villager_s {
    unsigned long nb_fights_left;
    unsigned long id;
    unsigned char drink;
    pthread_t thread_id;
    struct panoramix_s *info;
} villager_t;

typedef struct panoramix_s {
    unsigned long nb_villagers;
    unsigned long pot_size;
    unsigned long nb_fights;
    unsigned long nb_refills;
    unsigned long pot_quantity;
    sem_t pano_sem;
    sem_t vil_sem;
    pthread_mutex_t mutex;
    villager_t **villagers;
} panoramix_t;

int panoramix(panoramix_t *info);
int print_error(char *err);
