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
        void initCircuit(std::vector<std::tuple<std::string, std::string>> chipsets);
        void initLinks(std::vector<std::tuple<std::string, size_t, std::string, size_t>> links);
        std::map<std::string, std::unique_ptr<nts::IComponent>> &getComponents(void);
        std::vector<std::tuple<std::string, size_t, std::string, size_t>> getLinks(void);
    protected:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _Components;
        std::vector<std::tuple<std::string, size_t, std::string, size_t>> _links;
    private:
};

#endif /* !CIRCUIT_HPP_ */
