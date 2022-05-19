/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Fantasia
*/

#pragma once

#include "APizza.hpp"

namespace plazza {
    class Fantasia : public APizza {
        public:
            Fantasia(uint64_t id, PizzaSize size) : APizza(id, size) {
                _type = FANTASIA;
                _cookTime = 4;
                _ingredients.push_back(DOE);
                _ingredients.push_back(TOMATO);
                _ingredients.push_back(EGGPLANT);
                _ingredients.push_back(GOAT_CHEESE);
                _ingredients.push_back(CHIEF_LOVE);
            };
            ~Fantasia() = default;
        protected:
        private:
    };
}
