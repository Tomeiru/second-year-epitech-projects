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
    _circuit.initLinks(_data.getLinksVec(), _data.getOutputFirstLinksVec(), _data.getOutputSecondLinksVec());
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
    return (addToQueue(command));
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
    if (state == nts::UNDEFINED) {
        std::cout << "U";
        return;
    }
    if (state == nts::NEWFALSE || state == nts::FALSE) {
        std::cout << "0";
        return;
    }
    if (state == nts::NEWTRUE || state == nts::TRUE) {
        std::cout << "1";
        return;
    }
}

void NanoLoop::displayInput(void)
{
    std::vector<std::tuple<std::string, std::string>> chipsets = _data.getChipsetVec();

    std::cout << "input(s): " << std::endl;
    for (size_t i = 0; i < chipsets.size(); i++) {
        if (std::get<0>(chipsets[i]) == "input" || std::get<0>(chipsets[i]) == "clock") {
            auto it = _circuit.getComponents().find(std::get<1>(chipsets[i]));
            std::cout << "  " << it->second->getName() << ": ";
            printState(it->second->compute(0));
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
            printState(it->second->compute(0));
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

void NanoLoop::clearQueue(void)
{
    while (_queue.empty() != true) {
        inputFunc(_queue[0]);
        _queue.erase(_queue.begin());
    }
}

void NanoLoop::getLinkLine(std::string nameGet, size_t pinGet)
{
    std::vector<std::tuple<std::string, size_t, std::string, size_t>> links = _data.getLinksVec();

    for (size_t i = 0; i < links.size(); i++) {
        if (std::get<2>(links[i]) == nameGet && std::get<3>(links[i]) == pinGet) {
            setStatefromLink(links[i], false);
        }
    }
    return;
}

void NanoLoop::setStateGate(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet == 1 || pinGet == 2 || pinGet == 5 || pinGet == 6 || pinGet == 12 || pinGet == 13 || pinGet == 9 || pinGet == 8) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 3) {
        getLinkLine(nameGet, 2);
        getLinkLine(nameGet, 1);
    }
    if (pinGet == 4) {
        getLinkLine(nameGet, 5);
        getLinkLine(nameGet, 6);
    }
    if (pinGet == 11) {
        getLinkLine(nameGet, 12);
        getLinkLine(nameGet, 13);
    }
    if (pinGet == 10) {
        getLinkLine(nameGet, 9);
        getLinkLine(nameGet, 8);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateInverter(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet == 1 || pinGet == 3 || pinGet == 5 || pinGet == 9 || pinGet == 11 || pinGet == 13) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 2) {
        getLinkLine(nameGet, 1);
    }
    if (pinGet == 4) {
        getLinkLine(nameGet, 3);
    }
    if (pinGet == 6) {
        getLinkLine(nameGet, 5);
    }
    if (pinGet == 8) {
        getLinkLine(nameGet, 9);
    }
    if (pinGet == 10) {
        getLinkLine(nameGet, 11);
    }
    if (pinGet == 12) {
        getLinkLine(nameGet, 13);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateAdder(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet == 1 || pinGet == 2 || pinGet == 3 || pinGet == 4 || pinGet == 5 || pinGet == 6 || pinGet == 7 || pinGet == 9 || pinGet == 15) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 10 || pinGet == 11 || pinGet == 12 || pinGet == 13 || pinGet == 14) {
        getLinkLine(nameGet, 1);
        getLinkLine(nameGet, 2);
        getLinkLine(nameGet, 3);
        getLinkLine(nameGet, 4);
        getLinkLine(nameGet, 5);
        getLinkLine(nameGet, 6);
        getLinkLine(nameGet, 7);
        getLinkLine(nameGet, 9);
        getLinkLine(nameGet, 15);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateFlipFlop(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet == 3 || pinGet == 4 || pinGet == 5 || pinGet == 6 || pinGet == 8 || pinGet == 9 || pinGet == 10 || pinGet == 11) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 1) {
        getLinkLine(nameGet, 3);
        getLinkLine(nameGet, 4);
    }
    if (pinGet == 2) {
        getLinkLine(nameGet, 5);
        getLinkLine(nameGet, 6);
    }
    if (pinGet == 12) {
        getLinkLine(nameGet, 8);
        getLinkLine(nameGet, 9);
    }
    if (pinGet == 13) {
        getLinkLine(nameGet, 10);
        getLinkLine(nameGet, 11);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateJohnson(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet == 13 || pinGet == 14 || pinGet == 15) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 1 || pinGet == 2 || pinGet == 3 || pinGet == 4 || pinGet == 5 || pinGet == 6 || pinGet == 7 || pinGet == 9 || pinGet == 10 || pinGet == 11  || pinGet == 12) {
        getLinkLine(nameGet, 13);
        getLinkLine(nameGet, 14);
        getLinkLine(nameGet, 15);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateCounter(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet == 10 || pinGet == 11) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 1 || pinGet == 2 || pinGet == 3 || pinGet == 4 || pinGet == 5 || pinGet == 6 || pinGet == 7 || pinGet == 9 || pinGet == 12 || pinGet == 13  || pinGet == 14 || pinGet == 15) {
        getLinkLine(nameGet, 10);
        getLinkLine(nameGet, 11);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateShift(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet == 1 || pinGet == 2 || pinGet == 3 || pinGet == 15) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 4 || pinGet == 5 || pinGet == 6 || pinGet == 7 || pinGet == 9 || pinGet == 10 || pinGet == 11 || pinGet == 12 || pinGet == 13 || pinGet == 14) {
        getLinkLine(nameGet, 1);
        getLinkLine(nameGet, 2);
        getLinkLine(nameGet, 3);
        getLinkLine(nameGet, 15);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateSelector(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (pinGet < 8 || (pinGet > 8 && pinGet < 14) || (pinGet == 15)) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 14) {
        getLinkLine(nameGet, 1);
        getLinkLine(nameGet, 2);
        getLinkLine(nameGet, 3);
        getLinkLine(nameGet, 4);
        getLinkLine(nameGet, 5);
        getLinkLine(nameGet, 6);
        getLinkLine(nameGet, 7);
        getLinkLine(nameGet, 9);
        getLinkLine(nameGet, 10);
        getLinkLine(nameGet, 11);
        getLinkLine(nameGet, 12);
        getLinkLine(nameGet, 13);
        getLinkLine(nameGet, 15);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStateDecoder(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet)
{
    auto componentToGet = _circuit.getComponents().find(nameGet);
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if ((pinGet > 3 && pinGet < 12) || (pinGet > 12 && pinGet < 21)) {
        getLinkLine(nameGet, pinGet);
        return;
    }
    if (pinGet == 4 || pinGet == 5 || pinGet == 6 || pinGet == 7 || pinGet == 9 || pinGet == 10 || pinGet == 11 || pinGet == 12 || pinGet == 13 || pinGet == 14) {
        getLinkLine(nameGet, 1);
        getLinkLine(nameGet, 2);
        getLinkLine(nameGet, 3);
        getLinkLine(nameGet, 21);
        getLinkLine(nameGet, 22);
        getLinkLine(nameGet, 23);
    }
    componentToGet->second->simulate(_tick);
    componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
}

void NanoLoop::setStatefromLink(std::tuple<std::string, size_t, std::string, size_t> link, bool first)
{
    std::string nameGet = (first == false ? std::get<0>(link) : std::get<2>(link));
    size_t pinGet = (first == false ? std::get<1>(link) : std::get<3>(link));
    auto componentToGet = _circuit.getComponents().find(nameGet);
    std::string nameSet = (first == true ? std::get<0>(link) : std::get<2>(link));
    size_t pinSet = (first == true ? std::get<1>(link) : std::get<3>(link));
    auto componentToSet = _circuit.getComponents().find(nameSet);

    if (componentToGet->second->getComp() == "Input" || componentToGet->second->getComp() == "Clock" || componentToGet->second->getComp() == "True" || componentToGet->second->getComp() == "False" || componentToGet->second->getComp() == "Output")
        componentToSet->second->setSinglePin(pinSet - 1, componentToGet->second->compute(pinGet - 1));
    if (componentToGet->second->getComp() == "4081" || componentToGet->second->getComp() == "4011" || componentToGet->second->getComp() == "4001" || componentToGet->second->getComp() == "4071" || componentToGet->second->getComp() == "4030")
        setStateGate(nameGet, pinGet, nameSet, pinSet);
    if (componentToGet->second->getComp() == "4069")
        setStateInverter(nameGet, pinGet, nameSet, pinSet);
    if (componentToGet->second->getComp() == "4008")
        setStateAdder(nameGet, pinGet, nameSet, pinSet);
    if (componentToGet->second->getComp() == "4013")
        setStateFlipFlop(nameGet, pinGet, nameSet, pinSet);
    if (componentToGet->second->getComp() == "4017")
        setStateJohnson(nameGet, pinGet, nameSet, pinSet);
    if (componentToGet->second->getComp() == "4040")
        setStateCounter(nameGet, pinGet, nameSet, pinSet);
    if (componentToGet->second->getComp() == "4094")
        setStateShift(nameGet, pinGet, nameSet,pinSet);
    if (componentToGet->second->getComp() == "4512")
        setStateSelector(nameGet, pinGet, nameSet, pinSet);
    if (componentToGet->second->getComp() == "4514")
        setStateDecoder(nameGet, pinGet, nameSet, pinSet);
    return;
}

void NanoLoop::simulateFunc(void)
{
    std::vector<std::tuple<std::string, std::string>> chipsets = _data.getChipsetVec();

    clearQueue();
    for (size_t i = 0; i < chipsets.size(); i++) {
        if (std::get<0>(chipsets[i]) == "clock") {
            auto it = _circuit.getComponents().find(std::get<1>(chipsets[i]));
            it->second->simulate(_tick);
        }
    }
    for (size_t i = 0; i < _data.getOutputFirstLinksVec().size(); i++) {
        setStatefromLink(_data.getOutputFirstLinksVec()[i], true);
    }
    for (size_t i = 0; i < _data.getOutputSecondLinksVec().size(); i++) {
        setStatefromLink(_data.getOutputSecondLinksVec()[i], false);
    }
    _tick += 1;
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
    if (it->second->getComp() != "Clock")
        return (it->second->setSinglePin(0, inputArgToTristate(match[3])));
    if (inputArgToTristate(match[3]) == nts::TRUE)
        return (it->second->setSinglePin(0, nts::NEWTRUE));
    if (inputArgToTristate(match[3]) == nts::FALSE)
        return (it->second->setSinglePin(0, nts::NEWFALSE));
    return (it->second->setSinglePin(0, nts::UNDEFINED));
}

void NanoLoop::addToQueue(std::string command)
{
    _queue.push_back(command);
}