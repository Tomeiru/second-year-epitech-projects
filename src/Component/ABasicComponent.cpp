/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** ABasicComponent
*/

#include "ABasicComponent.hpp"

ABasicComponent::ABasicComponent() : _Pin(1, nts::UNDEFINED), _NbrPin(1), _Type(BASIC)
{
}

ABasicComponent::~ABasicComponent()
{
}

void ABasicComponent::simulate(std::size_t tick)
{
    UNUSED(tick);
    return;
}

nts::Tristate ABasicComponent::compute(std::size_t pin)
{
    UNUSED(pin);
    return (nts::UNDEFINED);
}

void ABasicComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    UNUSED(pin);
    UNUSED(other);
    UNUSED(otherPin);
    return;
}

void ABasicComponent::dump() const
{
    return;
}

std::vector<nts::Tristate> ABasicComponent::getPinVector()
{
    return (_Pin);
}

nts::Tristate ABasicComponent::getSinglePin(std::size_t pin)
{
    if (pin == 0 || pin > _NbrPin)
        return (nts::UNDEFINED);
    return (_Pin[pin - 1]);
}

std::size_t ABasicComponent::getNbrPin()
{
    return (_NbrPin);
}

ComponentType ABasicComponent::getType()
{
    return (_Type);
}

void ABasicComponent::setSinglePin(std::size_t pin, nts::Tristate state)
{
    if (pin == 0 || pin > _NbrPin)
        return;
    _Pin[pin - 1] = state;
}