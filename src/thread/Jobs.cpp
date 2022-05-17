/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Jobs
*/

#include "Jobs.hpp"

void plazza::Jobs::addJob(Job &&job)
{
    ScopeLock{(IMutex&) _lock};

    _jobs.push(job);
}

plazza::Job plazza::Jobs::getJob()
{
    ScopeLock{(IMutex&) _lock};
    Job res = _jobs.front();

    _jobs.pop();
    return res;
}

size_t plazza::Jobs::getSize() const
{
    ScopeLock{(IMutex&) _lock};

    return _jobs.size();
}
