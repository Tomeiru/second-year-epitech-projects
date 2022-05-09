/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** main
*/

#include <iostream>
#include "process/CProcess.hpp"

void fork_start(plazza::IProcessCom &com, void *args)
{
    com.send((void*) std::string("Hello").c_str(), 5);
}

int main(int ac, char **av)
{
    {
        char buf[16] = {0};
        plazza::CProcess process(fork_start, nullptr);

        int size = process.getCom().recv(buf, 16);

        std::cout << size << ": '" << buf << "'" << std::endl;
    }
    return 0;
}
