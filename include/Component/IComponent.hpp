/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "NanoTekSpice.hpp"
#include "AnalogicGate.hpp"

namespace nts
{
    enum Tristate {
        IGNORE = 42,
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false,
    };

    class IComponent {
        public:
            ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::vector<nts::Tristate> getPinVector() = 0;
            virtual nts::Tristate getSinglePin(std::size_t pin) = 0;
            virtual std::size_t getNbrPin() = 0;
            virtual void setName(std::string name) = 0;
            virtual void setSinglePin(std::size_t pin, nts::Tristate state) = 0;
            virtual void setAllPin(nts::Tristate state) = 0;
    };

}

#endif /* !ICOMPONENT_HPP_ */
