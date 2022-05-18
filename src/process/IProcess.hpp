/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IProcess
*/

#pragma once

#include "../com/IProcessCom.hpp"

namespace plazza {
    class IProcess {
        public:
            using ProcessStartFct = void (*)(IProcessCom &com, void *args);

            virtual ~IProcess() = default;

            virtual void close() = 0;

            virtual IProcessCom &getCom() = 0;
    };
}
