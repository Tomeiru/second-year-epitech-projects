/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** BasicComponent
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IComponent.hpp"

class Component : public nts::IComponent {
    public:
        Component(std::string Name, std::size_t NbrPin);
        ~Component();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
        std::vector<nts::Tristate> getPinVector();
        nts::Tristate getSinglePin(std::size_t pin);
        std::size_t getNbrPin();
        std::string getName();
        void setName(std::string name);
        void setSinglePin(std::size_t pin, nts::Tristate state);
        void setAllPin(nts::Tristate state);
    protected:
        std::vector<nts::Tristate> _Pin;
        std::size_t _NbrPin;
        std::string _Comp;
        std::string _Name;
    private:
};

#endif /* !COMPONENT_HPP_ */