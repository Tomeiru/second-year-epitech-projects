/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Order
*/

#include "Order.hpp"

void plazza::Order::addPizzaToOrder(std::unique_ptr<plazza::IPizza> pizza)
{
    _pizzas.push_back(std::move(pizza));
}

bool plazza::Order::checkCompletion() const
{
    return _pizzas.size() == _pizzaCooked.size();
}

void plazza::Order::addPizzaCooked(uint64_t id)
{
    _pizzaCooked.push_back(id);
}

bool plazza::Order::isPizzaInThisOrder(uint64_t id)
{
    for (std::unique_ptr<IPizza> &pizza : _pizzas) {
        if (pizza->getId() == id)
            return true;
    }
    return false;
}

void plazza::Order::printCompletion() const
{
    std::cout << "Order " << _id << " is complete!" << std::endl;
}
