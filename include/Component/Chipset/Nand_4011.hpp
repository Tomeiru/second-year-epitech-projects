/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Nand_4011
*/

#ifndef NAND_4011_HPP_
#define NAND_4011_HPP_

#include "AnalogicGate.hpp"

class Nand_4011 : public Component{
    public:
        Nand_4011();
        ~Nand_4011();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !NAND_4011_HPP_ */
