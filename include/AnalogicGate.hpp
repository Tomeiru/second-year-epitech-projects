/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** AnalogicGate
*/

#ifndef ANALOGICGATE_HPP_
#define ANALOGICGATE_HPP_

#include "IComponent.hpp"

class AnalogicGate {
    public:
        AnalogicGate();
        ~AnalogicGate();
        nts::Tristate and_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate not_gate(nts::Tristate a);
        nts::Tristate nand_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b);
    protected:
    private:
};

#endif /* !ANALOGICGATE_HPP_ */

