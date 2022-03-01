/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Selector_4512
*/

#ifndef SELECTOR_4512_HPP_
#define SELECTOR_4512_HPP_

#include "Component.hpp"

class Selector_4512 : public Component{
    public:
        Selector_4512(std::string name);
        ~Selector_4512();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !SELECTOR_4512_HPP_ */
