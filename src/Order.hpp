/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Order
*/

#pragma once

#include <iostream>
#include "kitchen/pizzas/APizza.hpp"

namespace plazza {
    class Order {
        uint64_t _id;
        std::vector<std::unique_ptr<IPizza>> _pizzas;
        std::vector<uint64_t> _pizzaCooked;

        public:
            Order(uint64_t id) : _id(id) {};
            Order(Order &) = default;
            Order(Order &&) = default;
            ~Order() = default;

            void addPizzaToOrder(std::unique_ptr<IPizza> pizza);
            void addPizzaCooked(uint64_t id);
            bool isPizzaInThisOrder(uint64_t id);

            bool checkCompletion() const;
            void printCompletion() const;

            const std::vector<std::unique_ptr<IPizza>> &getPizzas() { return _pizzas; };
    };
}
