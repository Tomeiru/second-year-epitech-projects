/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** ArgHandler
*/

#pragma once

#include <vector>
#include <tuple>
#include <exception>
#include <string>
#include <stdexcept>

class ArgHandler {
    public:
        static std::vector<std::string> argvToVector(char **av);
        static std::tuple<double,int,int> convertVectorArgs(std::vector<std::string> args);
        static std::tuple<double,int,int> getArgs(int ac, char **av);
    protected:
    private:
};
