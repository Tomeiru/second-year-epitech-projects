/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CMutex
*/

#include <stdexcept>
#include "mutex/CMutex.hpp"

plazza::CMutex::CMutex()
{
    if (pthread_mutex_init(&this->_mutex, nullptr))
        throw std::runtime_error("Could not init mutex");
}

plazza::CMutex::~CMutex()
{
    pthread_mutex_destroy(&this->_mutex);
}

void plazza::CMutex::lock()
{
    pthread_mutex_lock(&this->_mutex);
}

void plazza::CMutex::unlock()
{
    pthread_mutex_unlock(&this->_mutex);
}

pthread_mutex_t &plazza::CMutex::getMutex()
{
    return this->_mutex;
}
