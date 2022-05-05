/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** UnixSocket
*/

#pragma once

#include <aio.h>
#include "com/IProcessCom.hpp"

namespace plazza {
    class UnixSocket : public IProcessCom {
        int _socket = -1;
        pid_t target = 0;

        public:
            UnixSocket();
            ~UnixSocket();

            void send(void *data, std::size_t size);
            int recv(void *buf, std::size_t size);
    };
}
