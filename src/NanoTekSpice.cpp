/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#include "NanoParser.hpp"

int main(int ac, char **av)
{
    NanoParser Parser;

    try {
        Parser.argumentCheck(ac);
        Parser.openFile(av[1]);
        Parser.checkFileContent();
    }
    catch (NanoError const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}