/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CCondVar
*/

#pragma once

#include <pthread.h>
#include "cond/ICondVar.hpp"

namespace plazza {
    class CCondVar : public ICondVar {
        pthread_cond_t _cond;
        pthread_mutex_t _mutex;

        public:
            CCondVar();
            ~CCondVar();

            void wait();

            void signal();
            void broadcast();
    };
}
