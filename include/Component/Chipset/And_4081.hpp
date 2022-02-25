/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** And_4081
*/

#ifndef AND_4081_HPP_
#define AND_4081_HPP_

#include "Component.hpp"

class And_4081 : public Component {
    public:
        And_4081(std::string name);
        ~And_4081();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !AND_4081_HPP_ */
