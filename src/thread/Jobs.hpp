/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Jobs
*/

#pragma once

#include <queue>
#include <iostream>
#include "CThread.hpp"
#include "../mutex/CMutex.hpp"
#include "../mutex/ScopeLock.hpp"

namespace plazza {
    struct Job {
        CThreadFct func;
        void *arg;
    };

    class Jobs {
        std::queue<Job> _jobs;
        CMutex _lock;

        public:
        void addJob(Job &job);
        Job getJob();
        size_t getSize() const;
    };
}
