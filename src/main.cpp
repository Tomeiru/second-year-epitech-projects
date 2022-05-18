/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** main
*/

#include "Reception.hpp"
#include "Logistic.hpp"

int main(int ac, char **av)
{
    std::tuple<double,int,int> args;
    try {
        args = ArgHandler::getArgs(ac, av);
    }catch (std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }

    plazza::Logistic logistic(args);
    std::unique_ptr<plazza::IThread> thread = std::make_unique<plazza::CThread>(plazza::logistic_main, &logistic);
    plazza::Reception reception(&logistic);

    reception.console();
    thread->join();
    return 0;
}
