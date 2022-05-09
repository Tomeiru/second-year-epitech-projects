/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IPizza
*/

#pragma once

#include <vector>
#include <ostream>
#include <memory>

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
                MUSHROOMS,
                STEAK,
                EGGPLANT,
                GOAT_CHEESE,
                CHIEF_LOVE,
            };
            ~IPizza() = default;

            virtual PizzaType getType() const = 0;
            virtual std::string getStringType() const = 0;
            virtual PizzaSize getSize() const = 0;
            virtual std::string getStringSize() const = 0;
            virtual const std::vector<Ingredient> &getIngredients() const = 0;
            virtual std::string getIngredientList() const = 0;
            virtual float getCookTime() const= 0;
    };
}

inline std::ostream &operator<<(std::ostream &os, const plazza::IPizza &pizza) {
    os << "The pizza is a " << (pizza.getStringType()) << " in size " << (pizza.getStringSize()) << ". The cook time without the multiplier is " << (pizza.getCookTime()) << " seconds." << std::endl << "The ingredient list is as follow: " << std::endl << pizza.getIngredientList();
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const std::unique_ptr<plazza::IPizza> &pizza) {
    os << "The pizza is a " << (pizza->getStringType()) << " in size " << (pizza->getStringSize()) << ". The cook time without the multiplier is " << (pizza->getCookTime()) << " seconds." << std::endl << "The ingredient list is as follow: " << std::endl << pizza->getIngredientList();
    return os;
}
