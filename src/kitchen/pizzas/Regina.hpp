/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Regina
*/

#pragma once

#include "APizza.hpp"

namespace plazza {
    class Regina : public APizza {
        public:
            Regina(uint64_t id, PizzaSize size) : APizza(id, size) {
                _type = REGINA;
                _cookTime = 2;
                _ingredients.push_back(DOE);
                _ingredients.push_back(TOMATO);
                _ingredients.push_back(GRUYERE);
                _ingredients.push_back(HAM);
                _ingredients.push_back(MUSHROOMS);
            };
            ~Regina() = default;

        protected:
        private:
    };
}
