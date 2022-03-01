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
    _circuit.initCircuit(_data.getChipsetVec());
    _circuit.initLinks(_data.getLinksVec());
    _tick = 0;
}

void NanoLoop::checkCommand(std::string command)
{
    std::smatch match;
    bool verif = false;

    if (command == "help" || command == "exit" || command == "display" || command == "simulate" || command == "loop" || command == "dump")
        return;
    if (std::regex_search(command, match, std::regex("([a-z0-9_]+)(=)([10U])")) && match[2].str().length() == 1 && match[3].str().length() == 1) {
        for (size_t i = 0; i < _data.getChipsetVec().size(); i++) {
            if (match[1].str() == std::get<1>(_data.getChipsetVec()[i])) {
                if (!(std::get<0>(_data.getChipsetVec()[i]) == "input" || std::get<0>(_data.getChipsetVec()[i]) == "clock"))
                    throw NanoError("Modifying an input only works for clock and input");
                verif = true;
            }
        }
        if (verif == false)
            throw NanoError("The name of the input doesn't correspond to any existant component");
        return;
    }
    throw NanoError("Wrong command, type help to get a list of command");
}

void NanoLoop::execCommand(std::string command)
{
    if (command == "help")
        return (helpFunc());
    if (command == "exit")
        return (exitFunc());
    if (command == "display")
        return (displayFunc());
    if (command == "simulate")
        return (simulateFunc());
    if (command == "loop")
        return (loopFunc());
    if (command == "dump")
        return (dumpFunc());
    return (inputFunc(command));
}

void NanoLoop::start(void)
{
    std::string command;

    std::cout << "> ";
    command = getInput();
    try {
        checkCommand(command);
    }
    catch (NanoError const &error) {
        std::cerr << error.what() << std::endl;
        return (start());
    }
    execCommand(command);
    return (start());
}

std::string NanoLoop::getInput(void)
{
    std::string ret;

    std::getline(std::cin, ret);
    if (std::cin.eof())
        throw NanoError("EOF");
    return (ret);
}

void NanoLoop::helpFunc(void)
{
    std::cout << "help: prints a list of every command" << std::endl;
    std::cout << "display: prints all the values of inputs and outputs sorted in ASCII order for the current tick" << std::endl;
    std::cout << "[inputName]=[0,1,U]: changes the value of an input (also apply to clock)" << std::endl;
    std::cout << "simulate: simulates a tick of the circuit" << std::endl;
    std::cout << "loop: continuously runs a simulation then display until SIGINT is received (CTRL + C)" << std::endl;
    std::cout << "dump: calls the dump method of every component" << std::endl;
    std::cout << "exit: closes the program" << std::endl;
}

void NanoLoop::exitFunc(void)
{
    throw NanoError("Exit");
}

void NanoLoop::printState(nts::Tristate state)
{
    if (state == nts::UNDEFINED)
        std::cout << "U";
    if (state == nts::TRUE)
        std::cout << "1";
    if (state == nts::FALSE)
        std::cout << "0";
}

void NanoLoop::displayInput(void)
{
    std::vector<std::tuple<std::string, std::string>> chipsets = _data.getChipsetVec();

    std::cout << "input(s): " << std::endl;
    for (size_t i = 0; i < chipsets.size(); i++) {
        if (std::get<0>(chipsets[i]) == "input" || std::get<0>(chipsets[i]) == "clock") {
            auto it = _circuit.getComponents().find(std::get<1>(chipsets[i]));
            std::cout << "  " << it->second->getName() << ": ";
            printState(it->second->getSinglePin(0));
            std::cout << std::endl;
        }
    }

}

void NanoLoop::displayOutput(void)
{
    std::vector<std::tuple<std::string, std::string>> chipsets = _data.getChipsetVec();

    std::cout << "output(s): " << std::endl;
    for (size_t i = 0; i < chipsets.size(); i++) {
        if (std::get<0>(chipsets[i]) == "output") {
            auto it = _circuit.getComponents().find(std::get<1>(chipsets[i]));
            std::cout << "  " << it->second->getName() << ": ";
            printState(it->second->getSinglePin(0));
            std::cout << std::endl;
        }
    }
}

void NanoLoop::displayFunc(void)
{
    std::cout << "tick: " << _tick << std::endl;
    displayInput();
    displayOutput();
}

void NanoLoop::simulateFunc(void)
{
    _tick += 1;
    std::cout << "simulate" << std::endl;
}

void NanoLoop::loopFunc(void)
{
    while (1) {
        simulateFunc();
        displayFunc();
    }
}

void NanoLoop::dumpFunc(void)
{
    std::vector<std::tuple<std::string, std::string>> chipsets = _data.getChipsetVec();

    for (size_t i = 0; i < chipsets.size(); i++) {
        auto it = _circuit.getComponents().find(std::get<1>(chipsets[i]));
        it->second->dump();
        if (i != chipsets.size() - 1)
            std::cout << std::endl;
    }
}

nts::Tristate NanoLoop::inputArgToTristate(std::string inputValue)
{
    if (inputValue == "U")
        return (nts::UNDEFINED);
    if (inputValue == "1")
        return (nts::TRUE);
    return (nts::FALSE);
}

void NanoLoop::inputFunc(std::string command)
{
    std::smatch match;
    std::regex_search(command, match, std::regex("([a-z0-9_]+)(=)([10U])"));
    std::vector<std::tuple<std::string, std::string>> chipsets = _data.getChipsetVec();

    auto it = _circuit.getComponents().find(match[1].str());
    it->second->setSinglePin(0, inputArgToTristate(match[3]));
}