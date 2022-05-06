/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Serializer
*/

#pragma once

#include "IPizza.hpp"
#include <memory>

namespace plazza {
    class Serializer {
        public:
            struct PizzaSerialized {
                unsigned long id;
                IPizza::PizzaType type;
                IPizza::PizzaSize size;
            };

            Serializer() = delete;

            static PizzaSerialized serialize(IPizza &pizza);
            static std::unique_ptr<IPizza> deserialize(PizzaSerialized &pizza);
    };
}
