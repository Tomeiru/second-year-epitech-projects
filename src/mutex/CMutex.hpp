/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CMutex
*/

#pragma once

#include <pthread.h>
#include "IMutex.hpp"

namespace plazza {
    class CMutex {
        pthread_mutex_t _mutex;

        public:
            CMutex();
            ~CMutex();

            void lock();
            void unlock();
            pthread_mutex_t &getMutex();
    };
}
