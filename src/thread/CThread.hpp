/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CThread
*/

#pragma once

#include <pthread.h>
#include "thread/IThread.hpp"

namespace plazza {
    using CThreadFct = void *(*)(void*);

    class CThread : public IThread {
        pthread_t _thread;

        public:
            CThread(CThreadFct fct, void *arg);
            ~CThread();

            void join();
            pthread_t getThread();
    };
}
