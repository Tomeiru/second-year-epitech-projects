/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Jobs
*/

#pragma once

#include <queue>
#include <iostream>
#include <memory>
#include "CThread.hpp"
#include "../mutex/CMutex.hpp"
#include "../mutex/ScopeLock.hpp"

namespace plazza {
    class Job {
        public:
        virtual void execute() = 0;
    };

    class Jobs {
        std::queue<std::unique_ptr<Job>> _jobs;
        CMutex _lock;

        public:
        void addJob(std::unique_ptr<Job> &job);
        std::unique_ptr<Job> getJob();
        size_t getSize() const;
    };
}
