/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IProcessCom
*/

#pragma once

#include <cstddef>
#include "../process/ProcessType.hpp"

namespace plazza {
    class ProcessComSideUndef {};
    class ProcessComSideAlreadySet {};

    class IProcessCom {
        public:
            ~IProcessCom() = default;

            virtual void send(void *data, std::size_t size) = 0;
            virtual int recv(void *buf, std::size_t size) = 0;

            virtual void setComSide(ProcessType type) = 0;
    };
}
