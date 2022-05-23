/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** transation
*/

#include "transaction.h"
#include "conn.h"
#include "safe_malloc.h"

transaction_t *transaction_create(void *data,
transaction_execute_fct_t execute, transaction_free_fct_t free, list_t *list)
{
    transaction_t *transaction = safe_malloc(sizeof(transaction_t));
    static uint64_t id = 0;

    transaction->id = id++;
    transaction->data = data;
    transaction->execute = execute;
    transaction->free = free;
    push_back(list, transaction);
    return transaction;
}

void transaction_destroy(transaction_t *transaction, list_t *list)
{
    delete_node_with_data(list, transaction);
    transaction->free(transaction->data);
    free(transaction);
}

bool handle_transaction_with_id(uint64_t id, conn_t *conn, list_t *list)
{
    transaction_t *transaction = NULL;

    for (list_t cpy = *list; cpy; cpy = cpy->next) {
        if (((transaction_t*) cpy->data)->id == id) {
            transaction = cpy->data;
            break;
        }
    }
    if (!transaction)
        return true;
    transaction->execute(conn, transaction->data);
    transaction_destroy(transaction, list);
    return false;
}
