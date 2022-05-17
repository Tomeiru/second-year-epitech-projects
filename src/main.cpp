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
    Logistic *logistic = (Logistic *)arg;
    unsigned int nbOrder = 0;
    int queueSize = 0;

    while (1) {
        queueSize = logistic->getQueueSize();
        if (logistic->getEnd() == true)
            break;
        if (logistic->getStatus() == true) {
            std::cout << "Status!" << std::endl;
            logistic->toggleStatus();
            logistic->unlockMutex();
        }
        if (nbOrder < queueSize) {
            std::cout << queueSize - nbOrder << " order has been added to the queue!" << std::endl;
            nbOrder = queueSize;
        }
        if (nbOrder > queueSize) {
            std::cout << nbOrder - queueSize << " order has been removed from to the queue" << std::endl;
            nbOrder = queueSize;
        }
    }
    return (nullptr);
}

int main(int ac, char **av)
{
    try {
        std::tuple<double,int,int> args = ArgHandler::getArgs(ac, av);
    }catch (std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    Logistic logistic;
    std::unique_ptr<plazza::IThread> thread = std::make_unique<plazza::CThread>(handler, &logistic);
    Reception reception(&logistic);
    reception.console();
    thread->join();
    return 0;
}
