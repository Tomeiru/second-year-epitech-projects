/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CThread
*/

#include <unistd.h>
#include <stdexcept>
#include "CThread.hpp"

plazza::CThread::CThread(CThreadFct fct, void *arg)
{
    if (pthread_create(&this->_thread, NULL, fct, arg))
        throw std::runtime_error("Could not init thread");
}

plazza::CThread::~CThread()
{
    pthread_cancel(this->_thread);
}

void plazza::CThread::join()
{
    pthread_join(this->_thread, nullptr);
}

void plazza::CThread::sleep(float sec)
{
    usleep(sec * 1000000);
}
