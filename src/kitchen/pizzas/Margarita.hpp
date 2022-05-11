/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Margarita
*/

#pragma once

#include "APizza.hpp"

namespace plazza {
    class Margarita : public APizza {
        public:
            Margarita(uint64_t id, PizzaSize size) : APizza(id, size) {
                _type = MARGARITA;
                _cookTime = 1;
                _ingredients.push_back(DOE);
                _ingredients.push_back(TOMATO);
                _ingredients.push_back(GRUYERE);
            }
            ~Margarita() = default;
        protected:
        private:
    };
}
