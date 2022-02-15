/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** BasicComponent
*/

#ifndef ABASICCOMPONENT_HPP_
#define ABASICCOMPONENT_HPP_

#include "IComponent.hpp"

enum ComponentType {
    BASIC,
    GATE,
    ADVANCED
};

class ABasicComponent : public nts::IComponent {
    public:
        ABasicComponent();
        ~ABasicComponent();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
        std::vector<nts::Tristate> getPinVector();
        nts::Tristate getSinglePin(std::size_t pin);
        std::size_t getNbrPin();
        ComponentType getType();
        void setSinglePin(std::size_t pin, nts::Tristate state);
    protected:
        std::vector<nts::Tristate> _Pin;
        std::size_t _NbrPin;
        ComponentType _Type;
    private:
};

#endif /* !ABASICCOMPONENT_HPP_ */
