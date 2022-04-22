/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix
*/

#include "panoramix.h"

int print_error(char *err)
{
    fprintf(stderr, "%s\n", err);
    return (84);
}

void villager_drink(villager_t *vil)
{
    printf("Villager %lu: I need a drink... I see %lu servings left.\n"
    , vil->id, vil->info->pot_quantity);
    if (vil->info->pot_quantity)
        vil->info->pot_quantity = vil->info->pot_quantity - 1;
    else {
        printf("Villager %lu: Hey Pano wake up! We need more potion.\n",
        vil->id);
        sem_post(&vil->info->pano_sem);
        sem_wait(&vil->info->vil_sem);
        vil->info->pot_quantity = vil->info->pot_quantity - 1;
    }
    vil->drink = 1;
}

void *villager_thread(void *args)
{
    villager_t *vil = args;

    printf("Villager %lu: Going into battle!\n", vil->id);
    while (vil->nb_fights_left != 0) {
        if (!vil->drink) {
            pthread_mutex_lock(&vil->info->mutex);
            villager_drink(vil);
            pthread_mutex_unlock(&vil->info->mutex);
        }
        vil->nb_fights_left -= 1;
        printf("Villager %lu: Take that roman scum! Only %lu left.\n",
        vil->id, vil->nb_fights_left);
        vil->drink = 0;
    }
    printf("Villager %lu: I'm going to sleep now.\n", vil->id);
    return (NULL);
}

void *druid_thread(void *args)
{
    panoramix_t *info = args;

    printf("Druid: I'm ready... but sleepy...\n");
    while (info->nb_refills) {
        sem_wait(&info->pano_sem);
        info->nb_refills -= 1;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can \
only make %lu more refills after this one.\n", info->nb_refills);
        POT_QUAN = POT_SIZE;
        sem_post(&info->vil_sem);
    }
    printf("Druid: I'm out of viscum. I'm going back to ... zZz\n");
    return (NULL);
}

int panoramix(panoramix_t *info)
{
    pthread_t thread_id_pano;
    pthread_t thread_id_vil;

    pthread_create(&thread_id_pano, NULL, druid_thread, (void*)info);
    for (unsigned long i = 0; info->villagers[i]; i++) {
        pthread_create(&thread_id_vil, NULL, villager_thread,
        (void*)info->villagers[i]);
        info->villagers[i]->thread_id = thread_id_vil;
    }
    for (unsigned long i = 0; info->villagers[i]; i++)
        pthread_join(info->villagers[i]->thread_id, NULL);
    pthread_join(thread_id_pano, NULL);
    for (unsigned long i = 0; info->villagers[i]; i++)
        free(info->villagers[i]);
    free(info->villagers);
    pthread_mutex_destroy(&info->mutex);
    sem_destroy(&info->vil_sem);
    sem_destroy(&info->pano_sem);
    free(info);
    return (0);
}
