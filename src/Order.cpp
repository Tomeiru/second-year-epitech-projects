/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Order
*/

#include "Order.hpp"

plazza::Order::Order(uint64_t id)
{
    _id = id;
}

plazza::Order::~Order()
{
}

void plazza::Order::addPizzaToOrder(std::unique_ptr<plazza::IPizza> pizza)
{
    _pizzas.push_back(std::move(pizza));
}

bool plazza::Order::checkCompletion() const
{
    for (unsigned int i = 0; i <_pizzas.size(); i++)
        if (!_pizzas[i])
            return (false);
    return (true);
}

void plazza::Order::printCompletion() const
{
    std::cout << "Order " << _id << " is complete!" << std::endl;
}
