/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "Factory.hpp"

class Circuit {
    public:
        Circuit();
        ~Circuit();
        void initFactory(std::vector<std::tuple<std::string, std::string>> chipsets);

    protected:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _Components;
    private:
};

#endif /* !CIRCUIT_HPP_ */
