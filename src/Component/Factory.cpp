/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(void)>> Factory::factory_list {
    std::make_pair("input", []() {return std::make_unique<Input>();}),
    std::make_pair("true", []() {return std::make_unique<True>();}),
    std::make_pair("false", []() {return std::make_unique<False>();}),
    std::make_pair("clock", []() {return std::make_unique<Clock>();}),
    std::make_pair("output", []() {return std::make_unique<Output>();}),
    std::make_pair("4008", []() {return std::make_unique<Adder_4008>();}),
    std::make_pair("4081", []() {return std::make_unique<And_4081>();}),
    std::make_pair("4040", []() {return std::make_unique<Counter_4040>();}),
    std::make_pair("4514", []() {return std::make_unique<Decoder_4514>();}),
    std::make_pair("4008", []() {return std::make_unique<FlipFlop_4013>();}),
    std::make_pair("4081", []() {return std::make_unique<Inverter_4069>();}),
    std::make_pair("4040", []() {return std::make_unique<Johnson_4017>();}),
    std::make_pair("4514", []() {return std::make_unique<Nand_4011>();}),
    std::make_pair("4008", []() {return std::make_unique<Nor_4001>();}),
    std::make_pair("4081", []() {return std::make_unique<Or_4071>();}),
    std::make_pair("4040", []() {return std::make_unique<RAM_4801>();}),
    std::make_pair("4514", []() {return std::make_unique<Register_4094>();}),
    std::make_pair("4514", []() {return std::make_unique<ROM_2716>();}),
    std::make_pair("4008", []() {return std::make_unique<Selector_4512>();}),
    std::make_pair("4081", []() {return std::make_unique<Xor_4030>();}),
    std::make_pair("logger", []() {return std::make_unique<Logger>();})
};

std::unique_ptr<nts::IComponent> Factory::createComponent(std::string &name)
{
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent> ()>>::iterator comp = factory_list.find(name);

    return ((comp->second)());
}