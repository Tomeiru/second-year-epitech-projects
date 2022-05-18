/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CCondVar
*/

#include <iostream>
#include <stdexcept>
#include "CCondVar.hpp"

plazza::CCondVar::CCondVar()
{
    if (pthread_mutex_init(&this->_mutex, NULL))
        throw std::runtime_error("Could not init mutex");
    if (pthread_cond_init(&this->_cond, NULL))
        throw std::runtime_error("Could not init conditional var");
}

plazza::CCondVar::~CCondVar()
{
    pthread_mutex_destroy(&this->_mutex);
    pthread_cond_destroy(&this->_cond);
}

void plazza::CCondVar::wait()
{
    pthread_cond_wait(&this->_cond, &this->_mutex);
}

void plazza::CCondVar::signal()
{
    pthread_cond_signal(&this->_cond);
}

void plazza::CCondVar::broadcast()
{
    pthread_cond_broadcast(&this->_cond);
}

void plazza::CCondVar::lock()
{
    pthread_mutex_lock(&this->_mutex);
}

void plazza::CCondVar::unlock()
{
    pthread_mutex_unlock(&this->_mutex);
}
