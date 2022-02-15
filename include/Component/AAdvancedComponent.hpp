/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AAdvancedComponent
*/

#ifndef AADVANCEDCOMPONENT_HPP_
#define AADVANCEDCOMPONENT_HPP_

#include "AGateComponent.hpp"

class AAdvancedComponent : public AGateComponent {
    public:
        AAdvancedComponent(std::size_t NbrPin);
        ~AAdvancedComponent();
    protected:
    private:
};

#endif /* !AADVANCEDCOMPONENT_HPP_ */
