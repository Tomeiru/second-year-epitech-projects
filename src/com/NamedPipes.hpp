/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** NamedPipes
*/

#pragma once

#include <sstream>
#include <iostream>
#include "IProcessCom.hpp"

namespace plazza {
    class NamedPipes : public IProcessCom {
        int _id = -1;
        int _readFd = -1;
        int _writeFd = -1;
        std::string _ptcPath;
        std::string _ctpPath;
        ProcessType _side = ProcessType::UNDEFINED;
        bool _closed = false;

        public:
            NamedPipes();
            ~NamedPipes();

            void send(void *data, std::size_t size);
            int recv(void *buf, std::size_t size);
            bool canRead();
            void closeCom() {
    std::cout << " WERE CLOSED " << std::endl;_closed = true; };
            bool isClosed() { return _closed; };

            void setComSide(ProcessType type);
    };
}
