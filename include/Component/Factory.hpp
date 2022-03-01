/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "True.hpp"
#include "Input.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "Adder_4008.hpp"
#include "And_4081.hpp"
#include "Counter_4040.hpp"
#include "Decoder_4514.hpp"
#include "FlipFlop_4013.hpp"
#include "Inverter_4069.hpp"
#include "Johnson_4017.hpp"
#include "Nand_4011.hpp"
#include "Nor_4001.hpp"
#include "Or_4071.hpp"
#include "RAM_4801.hpp"
#include "Register_4094.hpp"
#include "ROM_2716.hpp"
#include "Selector_4512.hpp"
#include "Xor_4030.hpp"
#include "NanoError.hpp"

class Factory {
    public:
        Factory();
        ~Factory();
        static std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(void)>> factory_list;
        std::unique_ptr<nts::IComponent> createComponent(std::string &comp);
    protected:
    private:
};

#endif /* !FACTORY_HPP_ */
