/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Inverter_4069
*/

#ifndef INVERTER_4069_HPP_
#define INVERTER_4069_HPP_

#include "AnalogicGate.hpp"

class Inverter_4069 : public Component {
    public:
        Inverter_4069();
        ~Inverter_4069();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !INVERTER_4069_HPP_ */
