/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** ArgHandler
*/

#include "ArgHandler.hpp"


std::vector<std::string> ArgHandler::argvToVector(char **av)
{
    std::vector<std::string> ret;
    for (int i = 0; av[i]; i++)
        ret.push_back(av[i]);
    return (ret);
}

std::tuple<double,int,int> ArgHandler::convertVectorArgs(std::vector<std::string> args)
{
    double a = std::stod(args[0]);
    int b = std::stoi(args[1]);
    int c = std::stoi(args[2]);
    std::tuple<double,int,int> ret = {a,b,c};
    return (ret);
}

std::tuple<double,int,int> ArgHandler::getArgs(int ac, char **av)
{
    if (ac != 4)
        throw std::invalid_argument("wrong argument number");
    std::vector<std::string> args = argvToVector(av + 1);
    std::tuple<double,int,int> ret = convertVectorArgs(args);
    int temp = (int)std::get<0>(ret);
    double tempf = (double)std::get<0>(ret);
    tempf -= temp;
    if (std::get<0>(ret) <= 0 || (tempf != 0 && temp >= 1))
        throw std::invalid_argument("invalid multiplier");
    if (std::get<1>(ret) <= 0)
        throw std::invalid_argument("invalid number of cooks per kitchen");
    if (std::get<2>(ret) < 0)
        throw std::invalid_argument("invalid replacement of ingredients time");
    return (ret);
}
