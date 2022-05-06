/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Serialize
*/

#include "Serializer.hpp"

plazza::Serializer::PizzaSerialized plazza::Serializer::serialize(IPizza &pizza)
{
    (void)pizza;
}

std::unique_ptr<plazza::IPizza> plazza::Serializer::deserialize(PizzaSerialized &pizza)
{
    (void)pizza;
}
