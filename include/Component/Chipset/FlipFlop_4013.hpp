/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** FlipFlop_4013
*/

#ifndef FLIPFLOP_4013_HPP_
#define FLIPFLOP_4013_HPP_

#include "AnalogicGate.hpp"

class FlipFlop_4013 : public Component{
    public:
        FlipFlop_4013();
        ~FlipFlop_4013();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !FLIPFLOP_4013_HPP_ */
