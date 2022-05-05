/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

plazza::SecuredThread::SecuredThread(CThreadFct fct, void *arg)
    : CThread(fct, arg), _joined(false)
{
}

plazza::SecuredThread::~SecuredThread()
{
}

bool plazza::SecuredThread::isJoined() const
{
    return _joined;
}

void plazza::SecuredThread::join()
{
    pthread_join(this->_thread, nullptr);
    _joined = true;
}

plazza::ThreadPool::ThreadPool()
    : _lastThread(0)
{
}

plazza::ThreadPool::~ThreadPool()
{
}

void plazza::ThreadPool::join()
{
    for (unsigned int i = 0; i < _threadTab.size(); i++) {
        if (_threadTab[i].isJoined() == false)
            _threadTab[i].join();
    }
}

void plazza::ThreadPool::add_thread(CThreadFct fct, void *arg)
{
    _threadTab.push_back(SecuredThread(fct, arg));
}
