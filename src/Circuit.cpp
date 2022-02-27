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

void Circuit::initFactory(std::vector<std::tuple<std::string, std::string>> chipsets)
{
    Factory factory;

    for (size_t i = 0; i < chipsets.size(); i++) {
        _Components.emplace(std::get<1>(chipsets[i]), factory.create(std::get<0>(chipsets[i])));
        _Components[std::get<1>(chipsets[i])].get()->setName(std::get<1>(chipsets[i]));
        std::cout << _Components[std::get<1>(chipsets[i])].get()->getName() << " || " << _Components[std::get<1>(chipsets[i])].get()->getNbrPin() << std::endl;
    }
}
