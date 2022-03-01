/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** omponent
*/

#include "Component.hpp"

Component::Component(std::string Name, std::size_t NbrPin) : _Comp(Name), _Pin(NbrPin, nts::UNDEFINED), _NbrPin(NbrPin)
{
    setAllPin(nts::UNDEFINED);
}

Component::~Component()
{
}

void Component::simulate(std::size_t tick)
{
    UNUSED(tick);
    return;
}

nts::Tristate Component::compute(std::size_t pin)
{
    UNUSED(pin);
    return (nts::UNDEFINED);
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    UNUSED(pin);
    UNUSED(other);
    UNUSED(otherPin);
    return;
}

void Component::dump() const
{
    std::cout << "Name: " << _Name << std::endl;
    std::cout << "Type of Component: " << _Comp << std::endl;
    std::cout << "Total number of pin: " << _NbrPin << std::endl;
}

std::vector<nts::Tristate> Component::getPinVector()
{
    return (_Pin);
}

nts::Tristate Component::getSinglePin(std::size_t pin)
{
    return (_Pin[pin]);
}

std::size_t Component::getNbrPin()
{
    return (_NbrPin);
}

std::string Component::getName()
{
    return (_Name);
}

void Component::setSinglePin(std::size_t pin, nts::Tristate state)
{
    _Pin[pin] = state;
}

void Component::setAllPin(nts::Tristate state)
{
    if (getNbrPin() != 1) {
        for (size_t i = 0; i < _NbrPin; i++)
            _Pin[i] = state;
        setSinglePin(_NbrPin/2 - 1, nts::Tristate::IGNORE);
        setSinglePin(_NbrPin - 1, nts::Tristate::IGNORE);
        return;
    }
    else {
        setSinglePin(0, state);
    }
}

void Component::setName(std::string name)
{
    _Name = name;
}