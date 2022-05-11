/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CProcess
*/

#pragma once

#include <aio.h>
#include "IProcess.hpp"
#include "../com/NamedPipes.hpp"

namespace plazza {
    class CProcess : public IProcess {
        pid_t _pid = 0;
        NamedPipes _com;

        public:
            CProcess(ProcessStartFct fct, void *args);
            ~CProcess();

            void close();

            IProcessCom &getCom();

        protected:
        private:
    };
}
