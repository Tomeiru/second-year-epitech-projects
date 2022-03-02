/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Register_4096
*/

#ifndef REGISTER_4094_HPP_
#define REGISTER_4094_HPP_

#include "AnalogicGate.hpp"

class Register_4094 : public Component {
    public:
        Register_4094();
        ~Register_4094();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !REGISTER_4094_HPP_ */
