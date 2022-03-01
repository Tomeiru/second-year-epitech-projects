/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "Component.hpp"

class True : public Component {
    public:
        True(std::string name);
        ~True();
        void simulate(std::size_t tick);

    protected:
    private:
};

#endif /* !TRUE_HPP_ */
