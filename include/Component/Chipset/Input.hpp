/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Component.hpp"

class Input : public Component {
    public:
        Input(std::string name);
        ~Input();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !INPUT_HPP_ */
