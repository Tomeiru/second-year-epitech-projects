/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Counter_4040
*/

#ifndef COUNTER_4040_HPP_
#define COUNTER_4040_HPP_

#include "Component.hpp"

class Counter_4040 : public Component{
    public:
        Counter_4040(std::string name);
        ~Counter_4040();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !COUNTER_4040_HPP_ */
