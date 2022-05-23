/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** transation
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "chained_list.h"

typedef struct conn_s conn_t;

typedef void (*transaction_execute_fct_t)(conn_t *conn, void*);
typedef void (*transaction_free_fct_t)(void*);

typedef struct transaction_s {
    uint64_t id;
    void *data;
    transaction_execute_fct_t execute;
    transaction_free_fct_t free;
} transaction_t;

transaction_t *transaction_create(void *data,
transaction_execute_fct_t execute, transaction_free_fct_t free, list_t *list);
void transaction_destroy(transaction_t *transaction, list_t *list);
bool handle_transaction_with_id(uint64_t id, conn_t *conn, list_t *list);
