/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** CommandFunction
*/

#include "NanoLoop.hpp"

void helpFunc(void)
{
    std::cout << "help: prints a list of every command" << std::endl;
    std::cout << "display: prints all the values of inputs and outputs sorted in ASCII order for the current tick" << std::endl;
    std::cout << "[inputName]=[0,1,U]: changes the value of an input (also apply to clock)" << std::endl;
    std::cout << "simulate: simulates a tick of the circuit" << std::endl;
    std::cout << "loop: continuously runs a simulation then display until SIGINT is received (CTRL + C)" << std::endl;
    std::cout << "dump: calls the dump method of every component" << std::endl;
    std::cout << "exit: closes the program" << std::endl;
}

void exitFunc(void)
{
    throw NanoError("Exit");
}

void displayFunc(void)
{

}

void simulateFunc(void)
{

}

void loopFunc(void)
{

}

void dumpFunc(void)
{

}

void inputFunc(std::string state)
{

}