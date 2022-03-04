/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** RAM_4801
*/

#ifndef RAM_4801_HPP_
#define RAM_4801_HPP_

#include "AnalogicGate.hpp"

class RAM_4801 : public Component {
    public:
        RAM_4801();
        ~RAM_4801();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !RAM_4801_HPP_ */
