/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AAdvancedComponent
*/

#include "AAdvancedComponent.hpp"

AAdvancedComponent::AAdvancedComponent(std::size_t NbrPin) : AGateComponent::AGateComponent()
{
    std::vector <nts::Tristate> Pin(NbrPin, nts::UNDEFINED);

    _Pin = Pin;
    _NbrPin = NbrPin;
    _Type = ADVANCED;
}

AAdvancedComponent::~AAdvancedComponent()
{
}
