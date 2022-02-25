/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** omponent
*/

#include "Component.hpp"

Component::Component(std::string Name, std::size_t NbrPin) : _Comp(Name), _Pin(NbrPin, nts::UNDEFINED), _NbrPin(1)
{
    setSinglePin(NbrPin/2, nts::Tristate::IGNORE);
    setSinglePin(NbrPin, nts::Tristate::IGNORE);
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
    return;
}

std::vector<nts::Tristate> Component::getPinVector()
{
    return (_Pin);
}

nts::Tristate Component::getSinglePin(std::size_t pin)
{
    if (pin == 0 || pin > _NbrPin)
        return (nts::UNDEFINED);
    return (_Pin[pin - 1]);
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
    if (pin == 0 || pin > _NbrPin)
        return;
    _Pin[pin - 1] = state;
}

void Component::setAllPin(nts::Tristate state)
{
    for (int i = 0; i < _NbrPin; i++) {
        _Pin[i] = state;
    }
}

void Component::setName(std::string name)
{
    _Name = name;
}