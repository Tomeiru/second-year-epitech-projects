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

std::vector<std::tuple<std::string, size_t, std::string, size_t>> Circuit::getLinks(void)
{
    return (_links);
}

std::vector<std::tuple<std::string, size_t, std::string, size_t>> Circuit::getOutputFirstLinks(void)
{
    return (_outputFirstLinks);
}

std::vector<std::tuple<std::string, size_t, std::string, size_t>> Circuit::getOutputSecondLinks(void)
{
    return (_outputSecondLinks);
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &Circuit::getComponents(void)
{
    return (_Components);
}

void Circuit::initCircuit(std::vector<std::tuple<std::string, std::string>> chipsets)
{
    Factory factory;

    for (size_t i = 0; i < chipsets.size(); i++) {
        _Components.emplace(std::get<1>(chipsets[i]), factory.createComponent(std::get<0>(chipsets[i])));
        _Components[std::get<1>(chipsets[i])].get()->setName(std::get<1>(chipsets[i]));
    }
}

void Circuit::initLinks(std::vector<std::tuple<std::string, size_t, std::string, size_t>> links, std::vector<std::tuple<std::string, size_t, std::string, size_t>> outputFirstLinks, std::vector<std::tuple<std::string, size_t, std::string, size_t>> outputSecondLinks)
{
    _links = links;
    _outputFirstLinks = outputFirstLinks;
    _outputSecondLinks = outputSecondLinks;
}
