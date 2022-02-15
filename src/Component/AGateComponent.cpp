/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AGateComponent
*/

#include "AGateComponent.hpp"

AGateComponent::AGateComponent() : ABasicComponent::ABasicComponent()
{
    std::vector <nts::Tristate> Pin(12, nts::UNDEFINED);

    _Pin = Pin;
    _NbrPin = 12;
    _Type = GATE;
}

AGateComponent::~AGateComponent()
{
}
