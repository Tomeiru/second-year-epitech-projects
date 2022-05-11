/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Americana
*/

#pragma once

#include "APizza.hpp"

namespace plazza {
    class Americana : public APizza{
        public:
            Americana(uint64_t id, PizzaSize size) : APizza(id, size) {
                _type = AMERICANA;
                _cookTime = 2;
                _ingredients.push_back(DOE);
                _ingredients.push_back(TOMATO);
                _ingredients.push_back(GRUYERE);
                _ingredients.push_back(STEAK);
            };
            ~Americana() = default;
        protected:
        private:
    };
}
