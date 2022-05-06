/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IPizza
*/

#pragma once

#include <vector>

namespace plazza {
    class IPizza {
        public:
            enum PizzaType {
                REGINA = 1,
                MARGARITA = 2,
                AMERICANA = 4,
                FANTASIA = 8
            };
            enum PizzaSize {
                S = 1,
                M = 2,
                L = 4,
                XL = 8,
                XXL = 16
            };
            enum Ingredient {
                DOE,
                TOMATO,
                GRUYERE,
                HAM,
                STEAK,
                GOAT_CHEESE,
                EGGPLANT,
                CHIEF_LOVE,
            };
            ~IPizza() = default;

            virtual PizzaType getType() = 0;
            virtual PizzaSize getSize() = 0;
            virtual const std::vector<Ingredient> &getIngrediants() = 0;
            virtual float getCookTime() = 0;
    };
}
