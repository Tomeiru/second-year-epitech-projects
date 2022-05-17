/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

void *worker_main(void *arg)
{
    plazza::PoolArg *args = (plazza::PoolArg*) arg;
    plazza::Job toDo;

    while (true) {
        while (args->jobs.getSize() == 0)
            args->condToDo.wait();
        toDo = args->jobs.getJob();
        toDo.func(toDo.arg);
    }
    return nullptr;
}

plazza::ThreadPool::ThreadPool(unsigned int threadNbr)
    : _size(threadNbr), _pollArgs((PoolArg) {_jobs, _condToDo})
{
    for (unsigned int i = 0; i != _size; i++)
        _threadTab.push_back({(plazza::CThreadFct) worker_main, &_pollArgs});
}

void plazza::ThreadPool::addJob(Job &job)
{
    _jobs.addJob(job);
    _condToDo.signal();
}
