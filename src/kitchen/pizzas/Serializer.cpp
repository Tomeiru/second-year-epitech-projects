/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Serialize
*/

#include "Serializer.hpp"
#include "APizza.hpp"

plazza::Serializer::PizzaSerialized plazza::Serializer::serialize(IPizza &pizza)
{
    PizzaSerialized serialized;
    serialized.id = pizza.getId();
    serialized.type = pizza.getType();
    serialized.size = pizza.getSize();

    return serialized;
}

std::unique_ptr<plazza::IPizza> plazza::Serializer::deserialize(PizzaSerialized &pizza)
{
    return APizza::pizzaFactory(pizza.id, pizza.type, pizza.size);
}
