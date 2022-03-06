/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#include "NanoLoop.hpp"
#include "Circuit.hpp"

int main(int ac, char **av)
{
    NanoParser Parser;
    NanoLoop Loop;

    try {
        Parser.argumentCheck(ac);
        Parser.openFile(av[1]);
        Parser.checkFileContent();
    }
    catch (NanoError const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    try {
        Loop.assignData(Parser);
        Loop.simulateFunc();
        Loop.start();
    }
    catch (NanoError const &error) {
        if (strcmp(error.what(), "EOF") == 0)
            return (0);
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}