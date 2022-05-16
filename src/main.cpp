/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** main
*/

#include "Reception.hpp"
#include "Logistic.hpp"

static void *handler(void *arg)
{
    std::vector<std::unique_ptr<plazza::Order>> *queue = (std::vector<std::unique_ptr<plazza::Order>> *)arg;
    unsigned int nbOrder = 0;

    while (1) {
        if (nbOrder < queue->size()) {
            std::cout << queue->size() - nbOrder << " order has been added to the queue!" << std::endl;
            nbOrder = queue->size();
        }
        if (nbOrder > queue->size()) {
            std::cout << nbOrder -queue->size() << " order has been removed from to the queue" << std::endl;
            nbOrder = queue->size();
        }
    }
    return (nullptr);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return 84;
    std::vector<std::unique_ptr<plazza::Order>> queue;
    plazza::CThread thread(handler, &queue);
    Reception reception(&queue);
    reception.console();
    return 0;
}
