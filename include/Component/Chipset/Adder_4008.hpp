/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Adder_4008
*/

#ifndef ADDER_4008_HPP_
#define ADDER_4008_HPP_

#include "AnalogicGate.hpp"

class Adder_4008 : public Component{
    public:
        Adder_4008();
        ~Adder_4008();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !ADDER_4008_HPP_ */
