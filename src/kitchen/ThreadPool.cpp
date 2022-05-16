/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

void *func(void *arg)
{
    plazza::Job toDo;
    plazza::PoolArg *args = (plazza::PoolArg*)arg;

    while (1) {
        for (; args->jobs.getSize() == 0; args->condToDo->wait());
        args->condToDo->lock();
        toDo = args->jobs.jobDone();
        args->condToDo->unlock();
        toDo.func(toDo.arg);
    }
}

plazza::ThreadPool::ThreadPool(unsigned int threadNbr)
    : _size(threadNbr)
{
    PoolArg arg;
    arg.condToDo = std::move(_condToDo);
    arg.jobs = _jobs;
    for (unsigned int i = 0; i != _size; i++)
        _threadTab.push_back({(plazza::CThreadFct)func, &arg});
}

plazza::ThreadPool::~ThreadPool()
{
}

void plazza::ThreadPool::addJob(Job job)
{
    _jobs.addJob(job);
    _condToDo->signal();
}
