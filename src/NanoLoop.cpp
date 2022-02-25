/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoLoop
*/

#include "NanoLoop.hpp"

NanoLoop::NanoLoop()
{
}

NanoLoop::~NanoLoop()
{
}

void NanoLoop::assignData(NanoParser &data)
{
    _data = data;
}

bool NanoLoop::checkCommand(std::string command)
{
    if (command == "help" || command == "exit" || command == "display" || command == "simulate" || command == "loop" || command == "dump")
        return (true);

    
    return (false);
}

void NanoLoop::execCommand(std::string command)
{
    void (*commandFunction[6])(void) = {
        helpFunc, exitFunc, displayFunc, simulateFunc, loopFunc, dumpFunc
    };
    std::vector<std::string> commandList = {
        "help", "exit", "display", "simulate", "loop", "dump"
    };
    for (size_t i = 0; i < commandList.size(); i++)
        if (command == commandList[i])
            return (commandFunction[i]());
    return (inputFunc(command.erase(0, 6)));
}

void NanoLoop::start(void)
{
    std::string command;

    std::cout << "> ";
    command = getInput();
    if (checkCommand(command) == false)
        std::cerr << "Wrong command, type help to get a list of command" << std::endl;
    else
        execCommand(command);
    start();
}

std::string NanoLoop::getInput(void)
{
    std::string ret;

    std::getline(std::cin, ret);
    if (std::cin.eof())
        throw NanoError("EOF");
    return (ret);
}