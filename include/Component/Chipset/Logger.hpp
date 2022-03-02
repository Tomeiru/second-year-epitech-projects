/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "AnalogicGate.hpp"

class Logger : public Component{
    public:
        Logger();
        ~Logger();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !LOGGER_HPP_ */

