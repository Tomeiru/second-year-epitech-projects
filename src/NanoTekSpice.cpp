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
    Circuit Circuit;

    try {
        Parser.argumentCheck(ac);
        Parser.openFile(av[1]);
        Parser.checkFileContent();
        Circuit.initCircuit(Parser.getChipsetVec());
        Circuit.initLinks(Parser.getLinksVec());
    }
    catch (NanoError const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    try {
        Loop.assignData(Parser);
        Loop.start();
    }
    catch (NanoError const &error) {
        return (0);
    }
    return (0);
}