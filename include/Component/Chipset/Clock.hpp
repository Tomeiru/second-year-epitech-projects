/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Component.hpp"

class Clock : public Component{
    public:
        Clock();
        ~Clock();
        void simulate(std::size_t tick);

    protected:
    private:
};

#endif /* !CLOCK_HPP_ */
