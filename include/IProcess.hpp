/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IProcess
*/

#pragma once

#include "IProcessCom.hpp"

namespace plazza {
    class ForkException {};

    class IProcess {
        public:
            ~IProcess() = default;

            virtual const IProcessCom &getCom() = 0;

        protected:
        private:
    };
}
