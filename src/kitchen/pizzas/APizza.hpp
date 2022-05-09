/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_

#include "IPizza.hpp"
#include <string>
#include <memory>
#include <map>
#include <functional>

namespace plazza {
    class APizza : public IPizza {
        public:
            APizza(PizzaSize size);
            ~APizza();
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
            static std::unique_ptr<IPizza> pizzaFactory(std::string type, std::string size);
        protected:
            PizzaType _type;
            PizzaSize _size;
            std::vector<Ingredient> _ingredients;
            float _cookTime;
        private:
    };
}

#endif /* !APIZZA_HPP_ */
