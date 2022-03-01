/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Component.hpp"

class False : public Component{
    public:
        False(std::string name);
        ~False();
        void simulate(std::size_t tick);

    protected:
    private:
};

#endif /* !FALSE_HPP_ */
