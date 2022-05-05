/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ScopeLock
*/

#pragma once

#include "mutex/IMutex.hpp"

namespace plazza {
    class ScopeLock {
        IMutex &_mutex;

        public:
            ScopeLock(IMutex &mutex) : _mutex(mutex) { _mutex.lock(); };
            ~ScopeLock() { _mutex.unlock(); };
    };
}
