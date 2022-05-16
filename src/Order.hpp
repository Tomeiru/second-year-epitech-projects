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
        public:
            Order(uint64_t id);
            Order(Order &) = default;
            Order(Order &&) = default;
            ~Order();
            void addPizzaToOrder(std::unique_ptr<plazza::IPizza> pizza);
            bool checkCompletion() const;
            void printCompletion() const;

        protected:
            uint64_t _id;
            std::vector<std::unique_ptr<plazza::IPizza>> _pizzas;
        private:
    };
}
