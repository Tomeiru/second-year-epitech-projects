/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** APizza
*/

#pragma once

#include "IPizza.hpp"
#include <string>
#include <memory>
#include <map>
#include <functional>

namespace plazza {
    class APizza : public IPizza {
        public:
            APizza(uint64_t id, PizzaSize size);
            ~APizza();

            uint64_t getId() const { return _id; };

            PizzaType getType() const;
            std::string getStringType() const;

            PizzaSize getSize() const;
            std::string getStringSize() const;

            const std::vector<Ingredient> &getIngredients() const;
            std::string getIngredientList() const;

            float getCookTime() const;

            static PizzaType stringToPizzaType(std::string type);
            static PizzaSize stringToPizzaSize(std::string size);

            static std::string pizzaTypeToString(PizzaType type);
            static std::string pizzaSizeToString(PizzaSize size);

            static std::string ingredientToString(Ingredient ingredient);

            static std::unique_ptr<IPizza> pizzaFactory(uint64_t id, PizzaType type, PizzaSize size);
            static std::unique_ptr<IPizza> pizzaFactory(uint64_t id, std::string type, std::string size);
        protected:
            uint64_t _id;
            PizzaType _type;
            PizzaSize _size;
            std::vector<Ingredient> _ingredients;
            float _cookTime;
        private:
    };
}
