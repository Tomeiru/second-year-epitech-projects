/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** main
*/

#include "Reception.hpp"

static void *handler(void *arg)
{
    std::vector<std::unique_ptr<plazza::IPizza>> *queue = (std::vector<std::unique_ptr<plazza::IPizza>> *)arg;

    while (1) {
        if (!queue->empty())
            std::cout << "I'm not empty!!!!!" << std::endl;
    }
    return (nullptr);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return 84;
    std::vector<std::unique_ptr<plazza::IPizza>> queue;
    plazza::CThread thread(handler, &queue);
    Reception reception(&queue);
    reception.console();
    return 0;
}
