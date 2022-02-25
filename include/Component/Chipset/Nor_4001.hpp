/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Nor_4001
*/

#ifndef NOR_4001_HPP_
#define NOR_4001_HPP_

#include "Component.hpp"

class Nor_4001 : public Component{
    public:
        Nor_4001(std::string name);
        ~Nor_4001();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !NOR_4001_HPP_ */
