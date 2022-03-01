/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "Component.hpp"

class Output : public Component {
    public:
        Output(std::string name);
        ~Output();
        void simulate(std::size_t tick);

    protected:
    private:
};

#endif /* !OUTPUT_HPP_ */
