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
            virtual ~IProcessCom() = default;

            // Return 0 if nothing to read
            // Return -1 if error occured
            virtual int recv(void *buf, std::size_t size) = 0;
            virtual void send(void *data, std::size_t size) = 0;
            virtual bool canRead() = 0;
            virtual void closeCom() = 0;
            virtual bool isClosed() = 0;

            virtual void setComSide(ProcessType type) = 0;
    };
}
