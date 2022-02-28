/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

void Circuit::initCircuit(std::vector<std::tuple<std::string, std::string>> chipsets)
{
    Factory factory;

    for (size_t i = 0; i < chipsets.size(); i++) {
        _Components.emplace(std::get<1>(chipsets[i]), factory.create(std::get<0>(chipsets[i])));
        _Components[std::get<1>(chipsets[i])].get()->setName(std::get<1>(chipsets[i]));
        _Components[std::get<1>(chipsets[i])].get()->setAllPin(nts::TRUE);
    }
}

void Circuit::initLinks(std::vector<std::tuple<std::string, size_t, std::string, size_t>> links)
{
    /*std::map<std::string, nts::Tristate *> first;
    std::map<std::string, nts::Tristate *> second;
    std::string firstName = _Components[std::get<0>(links[3])].get()->getName();
    size_t nbrPin = _Components[std::get<2>(links[3])].get()->getNbrPin();
    //nts::Tristate *firstPin = _Components[std::get<0>(links[3])].get()->getPinVector().front() + 1;
    std::string secondName = std::get<2>(links[3]);
    //nts::Tristate *secondPin = _Components[std::get<2>(links[3])].get()->getPinVector().front() + 1;

    std::cout << firstName << std::endl;
    //std::cout << *secondPin << std::endl;
    std::cout << nbrPin << std::endl;
    

    //if (*secondPin == nts::UNDEFINED)
        std::cout << "Pin 0 of " << secondName << " is Undefined !!" << std::endl;*/
    /*std::cout << _Components["adder"].get()->getName() << std::endl;
    std::cout << _Components["adder"].get()->getNbrPin() << std::endl;
    std::cout << _Components["adder"].get()->getPinVector()[15] << std::endl;*/
}
