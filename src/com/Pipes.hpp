/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Pipes
*/

#pragma once

#include "IProcessCom.hpp"

namespace plazza {
    class Pipes : public IProcessCom {
        int _parentToChild[2];
        int _childToParent[2];
        ProcessType _side = ProcessType::UNDEFINED;

        public:
            Pipes();
            ~Pipes();

            void send(void *data, std::size_t size);
            int recv(void *buf, std::size_t size);

            void setComSide(ProcessType type);
    };
}
