/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Xor_4030
*/

#ifndef XOR_4030_HPP_
#define XOR_4030_HPP_

#include "AnalogicGate.hpp"

class Xor_4030 : public Component {
    public:
        Xor_4030();
        ~Xor_4030();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !XOR_4030_HPP_ */
