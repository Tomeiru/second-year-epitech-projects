/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Jobs
*/

#include "Jobs.hpp"

plazza::Jobs::Jobs()
{
}

plazza::Jobs::~Jobs()
{
}

void plazza::Jobs::addJob(Job job)
{
    _jobs.push_back(job);
}

plazza::Job plazza::Jobs::jobDone()
{
    Job res = _jobs.front();

    _jobs.erase(_jobs.begin());
    return res;
}

std::vector<plazza::Job> plazza::Jobs::getJobs() const
{
    return _jobs;
}

size_t plazza::Jobs::getSize() const
{
    return _jobs.size();
}
